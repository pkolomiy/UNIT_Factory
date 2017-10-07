history.pushState({}, '', 'setup');

var p      = Tag(Id('window'), 'p');
var xml    = new XMLHttpRequest();
var tag_p  = 'none',
    action = 'none',
    but    = 'none';


function width_setup(arg) {
    if (arg.matches) {
        DTag('body')[0].style.height = '100vh';
    } else {
        DTag('body')[0].style.height = 'auto';
    }
}

window.matchMedia('(min-height: 400px)').addListener(width_setup);
width_setup(window.matchMedia('(min-height: 400px)'));

function list() {
    if (p)
        for (var i = 0; i < p.length; i++)
            p[i].addEventListener('click', highlight);
}

function highlight() {
    for (var i = 0; i < p.length; i++) {
        Tag(p[i], 'span')[0].style.visibility = 'hidden';
        p[i].style.background                 = 'none';
    }
    tag_p                                 = this;
    Tag(this, 'span')[0].style.visibility = 'visible';
    Tag(this, 'span')[0].addEventListener('click', function () {
        action              = 'backup';
        Sti('sure').display = 'block';
    });
    this.style.background = '#aaf';
    Id('restore').removeAttribute('style');
    Sti('restore').display = 'block';
}

if (Id('message').innerHTML === 'Database does not exist') {
    deactivate('delete');
    deactivate('make');
}
else
    deactivate('install');


function deactivate(name) {
    Sti(name).color     = '#ddd';
    Sti(name).cursor    = 'auto';
    Sti(name).border    = 'none';
    Sti(name).boxShadow = '2px 2px #888, -2px -2px #fff,0 2px #888,' +
        ' 2px 0 #888,-2px 2px #fff, 2px -2px #fff,3px 3px #444,' +
        '-2px 3px #444, 3px -2px #444';
    Sti(name).transform = 'none';
}

window.onclick = function (event) {

    if ((event.target === Id('delete') || event.target === Id('install')) &&
        event.target.style.cursor !== 'auto') {

        action              = 'database';
        Sti('sure').display = 'block';

        but = event.target === Id('delete') ? {
            activate: ['install'],
            deactivate: ['delete', 'make'],
            message: 'Database does not exist'
        } : {
            activate: ['delete', 'make'],
            deactivate: ['install'],
            message: 'Database exist'
        };
    }
    if (event.target === Id('yes')) {
        Sti('sure').display = 'none';
        if (action === 'database') {
            Id('message').innerHTML = but['message'];
            for (var i = 0; but['deactivate'][i]; i++)
                deactivate(but['deactivate'][i]);
            for (i = 0; but['activate'][i]; i++)
                Id(but['activate'][i]).removeAttribute('style');
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=manage_database&action=" + but['deactivate'][0] + "&parameter=0");
        } else if (action === 'backup') {
            tag_p.remove();
            deactivate('restore');
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=manage_database&action=remove backup&parameter=" + tag_p.innerHTML.substr(0, 30));
        } else if (action === 'make') {
            xml.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200 && action === 'make') {
                    Id('window').innerHTML = '';
                    if (this.responseText !== '') {
                        var arr = JSON.parse(this.responseText);
                        for (var i = 0; arr[i]; i++)
                            if (arr[i].length > 1)
                                Id('window').innerHTML += '<p>' + arr[i] + '<span>&#10005;</span></p>';
                    }
                    list();
                }
            };
            deactivate('restore');
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=manage_database&action=create backup&parameter=0");
        } else if (action === 'restore') {
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=manage_database&action=restore&parameter=" + tag_p.innerHTML.substr(0, 30));
            window.location.reload();
        }
    }
    if (event.target === Id('no'))
        Sti('sure').display = 'none';
    if (event.target === Id('make') && event.target.style.cursor !== 'auto') {
        Sti('sure').display = 'block';
        action              = 'make';
    }
    if (event.target === Id('restore') && event.target.style.cursor !== 'auto') {
        Sti('sure').display = 'block';
        action              = 'restore';
    }
    if (event.target === Id('tab1') || event.target === Id('tab2')) {
        Sti('beveled1').borderBottomColor = event.target === Id('tab1') ? '#fff' : '#ddd';
        Sti('beveled2').borderBottomColor = event.target === Id('tab1') ? '#ddd' : '#fff';
        Sti('message').display            = Sti('install').display = Sti('delete').display = event.target === Id('tab1') ? 'block' : 'none';
        Sti('window').display = Sti('make').display = Sti('restore').display = event.target === Id('tab1') ? 'none' : 'block';
    }
    if (event.target === Id('main'))
        window.location.href = "http://localhost:8080";
};

deactivate('restore');

list();
