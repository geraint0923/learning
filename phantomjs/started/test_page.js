var page = require('webpage').create();
page.open('http://yangy.me', function() {
	page.render('tsinghua_logo.png');
	console.log('render finish');
	phantom.exit();
});
