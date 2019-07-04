
import { GUIApplication, Root, Div, Indep, langou, New } from 'langou';
import { Color } from 'langou/value';
import { random } from 'langou/util';
import 'langou/css';
import './uu';

var test_count = 100000;

css.create({
	'.root': {
		backgroundColor: '#000',
	},
});

new GUIApplication({ multisample: 2 }).start(<Root />).onLoad = function() {
	var w = langou.displayPort.width;
	var h = langou.displayPort.height;
	var csss = {};

	for (var i = 0; i < test_count; i++) {
		var s = random(20, 30);
		var s2 = s / 2;
		csss['.root .css_' + i] = {
			backgroundColor: new Color(random(0, 255), random(0, 255), random(0, 255), 255),
			width: s,
			height: s,
			x: random(0, w + s) - s2,
			y: random(0, h + s) - s2,
		};
	}

	uu.start();

	css.create(csss);

	uu.log();

	this.root.class = 'root';

	New(
		<Div width="full" height="full">
			${
				Array.from({length:test_count}, (j, i)=>{
					return <Indep class=('css_' + i) />;
				})
			}
		</Div>, 
		this.root
	);

	uu.log();

}
