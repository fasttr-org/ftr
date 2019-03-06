/* ***** BEGIN LICENSE BLOCK *****
 * Distributed under the BSD license:
 *
 * Copyright (c) 2015, xuewen.chu
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of xuewen.chu nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL xuewen.chu BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***** END LICENSE BLOCK ***** */

#include <qgr/utils/util.h>

#if XX_LINUX

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>

/*
�����д����豸�ĵ��Ի����ֻ���ͨ��cat /proc/bus/input/devicesӦ�þ��ܹ����������豸�������Ϣ������

~ # cat /proc/bus/input/devices                                                 
I: Bus=0013 Vendor=0x0012 Product=0x1200 Version=0101                               
N: Name="TouchScreen"                                                    
P: Phys=                                                                        
S: Sysfs=/devices/virtual/input/input0                                          
U: Uniq=                                                                        
H: Handlers=event0                                                              
B: EV=b                                                                         
B: KEY=0                                                                        
B: ABS=1000003 
�������Ϣ�д�����vid,pid,�汾�ȣ��Լ�ABS��ʾ�������ľ����������룬���������ʾ16���ƣ�����

0x1000003=0001 0000 0000 0000 0000 0000 0011������Ϊ1�ı��ص�λ�þͱ�ʾ�������ᱨ����һ���͵��¼���
ǰ��bit0��bit1�Լ�bit24Ϊ1����ô��linux/input.h�ļ��ͱ�ʾ�¼�code����ABS_X=0x00, ABS_Y=0x01, 
ABS_PRESSURE=0x18���������ֱ��ʾ���������津����x���꣬y���꣬�Լ����º��ɿ���

���ǲ�ͬ�Ĵ�������x,y����ķ�Χ��һ����������Ҫͨ��input_absinfo�ṹ��ȥ��¼�õ��������ľ���ֵ��Ϣ��
*/

int test_linux_input2() 
{
	fd_set	rds;
	int	ret;
	struct input_event	event;
	struct timeval	time;

	int	fd = open( "/dev/input/event0", O_RDONLY );
	if ( fd < 0 ) {
		XX_ERR( "/dev/input/event0" );
		return(-1);
	}

	while (1) {
		FD_ZERO( &rds );
		FD_SET( fd, &rds );
		/*����select����Ƿ��ܹ���/dev/input/event0�豸��ȡ����*/
		ret = select( fd + 1, &rds, NULL, NULL, NULL );
		if ( ret < 0 ) 
		{
			XX_ERR( "select" );
			return(-1);
		}
		/*�ܹ���ȡ������*/
		else if ( FD_ISSET(fd, &rds) )
		{ 
			ret	= read( fd, &event, sizeof(struct input_event) );
			time	= event.time;
			LOG( "timeS=%d,timeUS=%d,type=%d,code=%d,value=%d\n", 
				time.tv_sec, time.tv_usec, event.type, event.code, event.value );
		}
	}

	/*�ر��豸�ļ����*/
	close( fd );

	/*
		����һ�´��������õ�������¼����棬timeS��timeUS�Ƿ���������¼���
		����PC�Ļ�һ���Ǵ�1970�����ڵ�ʱ�䣬�����ҵĿ�����Ļ���ϵͳ������ʼ�������ʱ�䡣

		type�Ļ����¼����ͣ�Ϊ3����EV_ABS=0x03��Ϊ0����EV_SYN=0x00��������Ϊ�¼��ķָ���

		code�Ļ������¼����Ͷ����������EV_ABS�Ļ�����ôcode�ʹ�ABS_XXX��ȥ�ң�
		typeΪEV_ABS��codeΪ0����ABS_X��codeΪ1����ABS_Y��codeΪ24����ABS_PRESSURE��
		��Щ��������linux/input.h�����ҵ���Ȼ��value������type��code��ǰ���µ�ֵ��
		����typeΪEV_ABS��codeΪABS_X����ôvalue�ʹ��������x�����ֵ��

		timeS=3143,timeUS=415046,type=3,code=0,value=325  ����x��ֵ                       
		timeS=3143,timeUS=415082,type=3,code=1,value=599  ����y��ֵ                              
		timeS=3143,timeUS=415092,type=3,code=24,value=1   ����                              
		timeS=3143,timeUS=415098,type=0,code=0,value=0    ͬ��                              
		timeS=3143,timeUS=430129,type=3,code=0,value=323  ����x��ֵ                              
		timeS=3143,timeUS=430169,type=3,code=1,value=592  ����y��ֵ                              
		timeS=3143,timeUS=430183,type=0,code=0,value=0    ͬ��                              
		timeS=3143,timeUS=445130,type=3,code=24,value=0   �ɿ�
	*/

	return(0);
}
 
int test_linux_input(int argc, char **argv)
{
	struct input_absinfo absI;
	int ret;

	int fd = open("/dev/input/event0", O_RDONLY);
	if (fd < 0) {
		XX_ERR("/dev/input/event0"); 
		return -1;
	}

	//�õ�X���abs��Ϣ
	ioctl(fd, EVIOCGABS(ABS_X), &absI);
	LOG("x abs lastest value=%d\n", absI.value);
	LOG("x abs min=%d\n", absI.minimum);
	LOG("x abs max=%d\n", absI.maximum);

	//�õ�y���abs��Ϣ
	ioctl(fd,EVIOCGABS(ABS_Y), &absI);
	LOG("y abs lastest value=%d\n", absI.value);
	LOG("y abs min=%d\n", absI.minimum);
	LOG("y abs max=%d\n", absI.maximum);

	//�õ���ѹ���abs��Ϣ
	ioctl(fd,EVIOCGABS(ABS_PRESSURE), &absI);
	LOG("pressure abs lastest value=%d\n", absI.value);
	LOG("pressure abs min=%d\n", absI.minimum);
	LOG("pressure abs max=%d\n", absI.maximum);

	close(fd);

	return test_linux_input2();
}

#else
int test_linux_input(int argc, char **argv) {return 0;}
#endif
