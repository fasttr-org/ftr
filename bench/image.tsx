
import { GUIApplication, Root, Image, Scroll, _CVD } from 'ftr';
import * as reader from 'ftr/reader';
import path from 'ftr/path';

new GUIApplication({ multisample: 2 }).start(
	<Root backgroundColor="#000">
		<Scroll width="full" height="full">
			{
				reader.readdirSync(__dirname + '/img2')
				.concat(reader.readdirSync(__dirname + '/img'))
				.filter(e=>path.extname(e.name).match(/\.(gif|jpeg|jpg|png|webp)$/i)).map(e=>
					(<Image borderBottom="5 #fff" width="100%" src={e.pathname} />)
				)
			}
		</Scroll>
	</Root>
);