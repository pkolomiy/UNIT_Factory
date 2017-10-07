var xml         = new XMLHttpRequest(),
    name        = (document.location.href.split('/'))[3],
    operation   = 0,
    dest        = 0,
    last_super  = 0,
    speed       = 0,
    vid         = 0,
    webstream   = 0,
    med         = 0,
    med2        = 0,
    med3        = 0,
    med4        = 0,
    interv      = 0,
    move        = 0,
    x           = 0,
    y           = 0,
    data        = 0,
    temp_data   = 0,
    buttons     = 0,
    scale       = 0,
    hh          = 0,
    scroll_load = 0;

if (name) {
    xml.onreadystatechange = function () {
        if (this.readyState === 4 && this.status === 200) {
            if (this.responseText === 'logged') {
                Sti('settings').display = 'block';
                Sti('add').display      = 'block';
            }
        }
    };
    xml.open('post', 'index.php', true);
    xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xml.send("operation=status&action=log in status&parameter=" + name);
}

function mozilla_kostyl() {
    if (Cls('layout')[0]) {
        if (SCls('layout').display === 'none') {
            SCls('main-body').alignItems = 'center';
        } else {
            SCls('main-body').alignItems = 'normal';
        }
    }
}

function OnMouseDown(e) {
    if ((window.event !== null ||
            e.button === 0) &&
        e.target === Id('super')) {
        x = e.x;
        y = e.y;

        document.onmousemove = OnMouseMove;
        document.body.focus();
        document.onselectstart = function () {
            return false;
        };
        e.target.ondragstart   = function () {
            return false;
        };
        return false;
    }
}

function OnMouseMove(e) {
    if (e.x && e.y && x && y) {
        Sti('super').left = (parseInt(Sti('super').left) + (e.x - x)) + 'px';
        Sti('super').top  = (parseInt(Sti('super').top) + (e.y - y)) + 'px';
    }
    x = e.x;
    y = e.y;
}


function OnMouseUp(e) {
    document.onmousemove   = null;
    document.onselectstart = null;
    e.target.ondragstart   = null;
    x                      = y = 0;
}

if (Id('main')) {
    var title              = Tag(DTag('header')[0], 'p')[0].innerHTML;
    Id('main').onmouseover = function () {
        Tag(DTag('header')[0], 'p')[0].innerHTML = 'Camagru';
    };
    Id('main').onmouseout  = function () {
        Tag(DTag('header')[0], 'p')[0].innerHTML = title;
    };
}


document.onmousedown = OnMouseDown;
document.onmouseup   = OnMouseUp;


if (((document.location.href.split('/'))[3].split('='))[0] === 'reset') {
    create_reset_form();

}

function icons_mouseover() {
    if (Cls('layout')[0]) {
        SCls('form-body').display = 'none';

        let imc = Cls('img-cell');
        if (imc) {
            for (var i = 0; i < imc.length; i++) {
                var img         = Tag(imc[i], 'img')[0];
                img.onmouseover = function () {
                    let icons = this.parentNode.getElementsByClassName('icons')[0];
                    if (icons) {
                        icons.style.visibility = 'visible';
                        icons.onmouseover      = function () {
                            this.style.visibility = 'visible';
                        };
                        icons.onmouseout       = function () {
                            this.style.visibility = 'hidden';
                        };
                    }
                };
                img.onmouseout  = function () {
                    if (this.parentNode.getElementsByClassName('icons')[0])
                        this.parentNode.getElementsByClassName('icons')[0].style.visibility = 'hidden';
                };
            }
        }
    }
}

var form = 0;
var arr  = [['Login', 'text'],
    ['Password', 'password'],
    ['Repeat Password', 'password'],
    ['Email', 'email']];
var arr2 = {
    'Login': 'No forbidden symbols, have one letter, more than 6 characters and less than 16',
    'Password': 'No forbidden symbols, have at least one letter, one number and be more than 8 symbols long',
    'New Password': 'No forbidden symbols, have at least one letter, one number and be more than 8 symbols long',
    'Repeat Password': 'Password didn\'t match',
    'Repeat New Password': 'Password didn\'t match',
    'Email': 'Invalid Email'
};

function message(text) {
    var cells = Cls('form-body')[0].childNodes,
        len   = cells.length;
    for (var i = 1; i < len; i++) {
        cells[1].remove();
    }
    var p   = crE('p'),
        div = crE('div');
    div.setAttribute('class', 'cell');
    p.classList.add('message');
    p.innerHTML = text;
    div.appendChild(p);
    Cls('form-body')[0].appendChild(div);
}

function remove_style(arr) {
    for (var i = 0; i < arr.length; i++) {
        arr[i].removeAttribute('style');
    }
}

function change_display(obj) {
    for (var i = 0; i < obj.length; i++) {
        for (var j = 0; j < obj[i][0].length; j++) {
            obj[i][0][j].display = obj[i][1][0];
        }
    }
}

function popup_text(text) {
    var cells = Cls('popup')[0].childNodes[0].childNodes,
        par   = crE('p');

    par.innerHTML   = text;
    par.style.color = '#f00';
    cells[0].appendChild(par);
    SCls('popup').display = 'flex';
}

function remove_popup() {
    var cells = Cls('popup')[0].childNodes[0].childNodes,
        len   = [cells[0].childNodes.length, cells[1].childNodes.length];

    for (var i = 0; i < 2; i++) {
        for (var j = 0; j < len[i]; j++) {
            cells[i].childNodes[0].remove();
        }
        cells[i].removeAttribute('style');
    }
    Cls('popup')[0].removeAttribute('style');
    Cls('popup')[0].childNodes[0].removeAttribute('style');
    if (med3)
        med3.removeListener(width_event2);
    if (med4)
        med4.removeListener(width_event3);
}

function cancel_function() {
    var cells = Cls('form-body')[0].childNodes;
    for (var i = 0; i < cells.length; i++) {
        if (cells[i] === Id('cancel').parentNode) {
            for (var j = 0; j < 3; j++) {
                cells[i].remove();
            }
            Tag(Id('confirm').parentNode, 'p')[0].style.display = 'none';
            Id('confirm').innerHTML                             = 'Change email';
            Id('confirm').classList.add('smaller');
            Id('confirm').id = 'change-mail';
            break;
        }
    }
}

function error() {
    var div = Cls('form-body')[0].childNodes[2],
        par = crE('p');

    DTag('input')[0].addEventListener('focus', Focus1);
    DTag('input')[1].addEventListener('focus', Focus1);
    if (!Tag(Cls('form-body')[0].childNodes[2], 'p')[0]) {
        par.classList.add('warn');
        par.innerHTML      = 'Error, try again';
        div.style.flexWrap = 'wrap';
        div.insertBefore(par, Tag(div, 'button')[0]);
    }
    Tag(div, 'p')[0].style.display = 'block';
}

function Focus1() {
    let tmp;
    if (tmp = Tag(Cls('form-body')[0].childNodes[2], 'p')[0])
        tmp.style.display = 'none';
}

function Focus2() {
    let tmp;
    if (tmp = Tag(Id('confirm').parentNode, 'p')[0])
        tmp.style.display = 'none';
}

var pass1  = 0,
    pass2  = 0,
    repeat = 0;

function onBlur() {

    var str  = this.value;
    var elem = this;


    if (this.getAttribute("placeholder") === 'Login' &&
        str.length >= 6 && str.length <= 16 && /^\w+$/.test(str) &&
        !(/^\d+$/.test(str.replace(/_/g, '0')))) {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                if (this.responseText === 'true')
                    Tag(elem.parentNode, 'span')[0].style.visibility = 'visible';
                else {
                    Tag(elem.parentNode, 'p')[0].innerHTML           = 'User already exist';
                    Tag(elem.parentNode, 'span')[0].style.visibility = 'hidden';
                    Tag(elem.parentNode, 'p')[0].style.display       = 'block';
                }
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=input&action=login validation&parameter=" + str);
    }
    else if ((this.getAttribute("placeholder") === 'Password' ||
            this.getAttribute("placeholder") === 'New Password') &&
        str.length >= 8 && /^\w+$/.test(str) &&
        !(/^\d+$/.test(str.replace(/_/g, '0'))) &&
        str.search('_') === -1 && str.search(/\d/) >= 0) {
        pass1 = str;
        if (pass2 !== 0 && pass2 !== '') {
            if (pass2 === str) {
                Tag(repeat.parentNode, 'p')[0].style.display       = 'none';
                Tag(repeat.parentNode, 'span')[0].style.visibility = 'visible';
                Tag(this.parentNode, 'span')[0].style.visibility   = 'visible';
            } else {
                Tag(repeat.parentNode, 'p')[0].innerHTML           = arr2[repeat.getAttribute("placeholder")];
                Tag(repeat.parentNode, 'span')[0].style.visibility = 'hidden';
                Tag(repeat.parentNode, 'p')[0].style.display       = 'block';
            }
        } else
            Tag(this.parentNode, 'span')[0].style.visibility = 'visible';
    }
    else if ((this.getAttribute("placeholder") === 'Repeat Password' ||
            this.getAttribute("placeholder") === 'Repeat New Password')) {
        repeat = this;
        if ((pass2 = str) === pass1) {
            Tag(this.parentNode, 'span')[0].style.visibility = 'visible';

        } else {
            Tag(this.parentNode, 'p')[0].innerHTML           = arr2[this.getAttribute("placeholder")];
            Tag(this.parentNode, 'span')[0].style.visibility = 'hidden';
            Tag(this.parentNode, 'p')[0].style.display       = 'block';
        }

    }
    else if (this.getAttribute("placeholder") === 'Email' || this.getAttribute("placeholder") === 'Your Email') {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                if (elem.getAttribute("placeholder") === 'Email') {
                    if (this.responseText === 'true')
                        Tag(elem.parentNode, 'span')[0].style.visibility = 'visible';
                    else {
                        Tag(elem.parentNode, 'p')[0].innerHTML           = this.responseText === 'no' ?
                            'User with this email already exist' : arr2['Email'];
                        Tag(elem.parentNode, 'span')[0].style.visibility = 'hidden';
                        Tag(elem.parentNode, 'p')[0].style.display       = 'block';
                    }
                } else {
                    if (this.responseText !== 'no') {
                        Tag(elem.parentNode, 'p')[0].innerHTML     = this.responseText === 'true' ?
                            'This email was not registered' : arr2['Email'];
                        Tag(elem.parentNode, 'p')[0].style.display = 'block';
                    }
                }
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=input&action=email validation&parameter=" + str);
    }

    else {
        Tag(this.parentNode, 'p')[0].innerHTML           = arr2[this.getAttribute("placeholder")];
        Tag(this.parentNode, 'span')[0].style.visibility = 'hidden';
        Tag(this.parentNode, 'p')[0].style.display       = 'block';
    }


}

function onFocus() {
    Tag(this.parentNode, 'p')[0].style.display = 'none';
}

function width_event(arg) {
    if (arg.matches) {
        remove_style([Id('right2'), Id('left2'), Cls('col-box')[0], Cls('img-col')[0]]);
    } else {
        change_display([[[Sti('right2'), SCls('col-box')], ['none']],
            [[Sti('left2')], ['flex']], [[SCls('img-col')], ['block']]]);
    }
}

function width_event2(arg) {
    if (arg.matches) {
        Cls('comments')[0].parentNode.style.height = '247px';
    } else {
        Cls('comments')[0].parentNode.style.height = '447px';
    }
}

function width_event3(arg) {
    if (arg.matches) {
        hh = Cls('comments')[0].parentNode.style.height;

        Cls('comments')[0].parentNode.style.height = 'auto';
        Cls('comments')[0].parentNode.style.width  = '100%';
        change_display([[[Sti('down2')], ['block']], [[SCls('comments'), SCls('likes')], ['none']]]);
    } else {
        if (hh)
            Cls('comments')[0].parentNode.style.height = hh;
        remove_style([Tag(Cls('popup')[0], 'img')[0], Cls('buts')[0], Cls('likes')[0],
            Cls('comments')[0], Id('down2'), Id('up2')]);
    }
}

function img_media(ev) {
    if (ev.matches) {
        Sti('super').width  = (parseInt(Sti('super').width) / 2) + 'px';
        Sti('super').height = (parseInt(Sti('super').height) / 2) + 'px';
        if (parseInt(Sti('super').top))
            Sti('super').top = (parseInt(Sti('super').top) / 2) + 'px';
        if (parseInt(Sti('super').left))
            Sti('super').left = (parseInt(Sti('super').left) / 2) + 'px';
        speed = 100;
    } else {
        Sti('super').width  = (parseInt(Sti('super').width) * 2) + 'px';
        Sti('super').height = (parseInt(Sti('super').height) * 2) + 'px';
        if (parseInt(Sti('super').top))
            Sti('super').top = (parseInt(Sti('super').top) * 2) + 'px';
        if (parseInt(Sti('super').left))
            Sti('super').left = (parseInt(Sti('super').left) * 2) + 'px';
        speed = 50;
    }
}

function img_add(target) {
    var img = crE('img'),
        div = Cls('capture')[0];

    img.src            = target.src;
    img.style.zIndex   = 1;
    img.style.position = 'absolute';
    img.style.top      = img.style.left = img.style.margin = 0;
    img.style.width  = window.innerWidth > 650 ? '200px' : '100px';
    img.style.height = window.innerWidth > 650 ? '224px' : '112px';
    img.id           = 'super';
    speed            = window.innerWidth > 650 ? 50 : 100;
    med2             = window.matchMedia('(max-width: 650px)');
    med2.addListener(img_media);
    div.appendChild(img);
}

function img_remove() {
    if (Id('super')) {
        med2.removeListener(img_media);
        Id('super').remove();
    }
}

function back_operations(option) {

    if (option === 'super-remove') {
        var sup = Cls('super-img')[0].childNodes;
        for (var i = 0; i < sup.length; i++) {
            sup[i].removeAttribute('style');
        }
    } else if (option === 'webcam-back') {
        webstream.getTracks()[0].stop();
        change_display([[[Sti('webcam'), Sti('upload')], ['block']],
            [[Sti('video'), SCls('buttons'), SCls('super-img')], ['none']]]);
    } else if (option === 'super-back') {
        remove_style([Id('next'), Cls('arrows')[0], Cls('arrows')[1]]);
        img_remove();
    } else if (option === 'upload-back') {
        change_display([[[Sti('webcam'), Sti('upload')], ['block']],
            [[Sti('canvas'), SCls('buttons'), SCls('super-img')], ['none']]]);
        Id('canvas').getContext('2d').clearRect(0, 0, Id('canvas').width, Id('canvas').height);
    } else if (option === 'post-back') {
        Id('canvas').getContext('2d').clearRect(0, 0, Id('canvas').width, Id('canvas').height);
        last_super.style.background = 'rgba(0, 0, 0, 0.15)';
        img                         = new Image();
        img.onload                  = function () {
            Id('canvas').getContext('2d').drawImage(img, 0, 0, Id('canvas').width, Id('canvas').height);
        };
        img.src                     = temp_data;
    }
}

function size_changer(w, h) {
    if (h !== 'scale') {
        Sti('super').width  = (parseInt(Sti('super').width) + w) + 'px';
        Sti('super').height = (parseInt(Sti('super').height) + h) + 'px';
        scale               = (parseInt(Sti('super').width) / parseInt(Sti('super').height)) * 100;
    } else {
        Sti('super').width  = (parseInt(Sti('super').width) + w) + 'px';
        Sti('super').height = ((parseInt(Sti('super').width) * 100) / scale) + 'px';
    }
}

function form_picture() {
    var img    = new Image(),
        pos_x  = parseInt(Sti('super').left),
        pos_y  = parseInt(Sti('super').top),
        size_x = parseInt(Sti('super').width),
        size_y = parseInt(Sti('super').height);
    temp_data  = Id('canvas').toDataURL();
    if (parseInt(getComputedStyle(Id('video')).width) === 266) {
        pos_x *= 2;
        pos_y *= 2;
        size_x *= 2;
        size_y *= 2;
    }
    if (dest === 'web')
        Id('canvas').getContext('2d').drawImage(Id('video'), 0, 0, 533, 400);
    img.src = Id('super').src;
    Id('canvas').getContext('2d').drawImage(img, pos_x, pos_y, size_x, size_y);
    data = Id('canvas').toDataURL();
}

function buttons_events() {
    Id('increase').addEventListener('mousedown', function () {
        let interval   = setInterval(function () {
            size_changer(1, 'scale');
        }, speed);
        this.onmouseup = function () {
            clearInterval(interval);
        };
        interv         = interval;
    });
    Id('increase').addEventListener('touchstart', function () {
        let interval    = setInterval(function () {
            size_changer(1, 'scale');
        }, speed);
        this.ontouchend = function () {
            clearInterval(interval);
        };
        interv          = interval;
    });
    Id('reduce').addEventListener('mousedown', function () {
        let interval   = setInterval(function () {
            size_changer(-1, 'scale');
        }, speed);
        this.onmouseup = function () {
            clearInterval(interval);
        };
        interv         = interval;
    });
    Id('reduce').addEventListener('touchstart', function () {
        let interval    = setInterval(function () {
            size_changer(-1, 'scale');
        }, speed);
        this.ontouchend = function () {
            clearInterval(interval);
        };
        interv          = interval;
    });


    Id('left').addEventListener('mousedown', function () {
        let interval   = setInterval(function () {
            size_changer(-1, 0);
        }, speed);
        this.onmouseup = function () {
            clearInterval(interval);
        };
        interv         = interval;
    });
    Id('left').addEventListener('touchstart', function () {
        let interval    = setInterval(function () {
            size_changer(-1, 0);
        }, speed);
        this.ontouchend = function () {
            clearInterval(interval);
        };
        interv          = interval;
    });
    Id('right').addEventListener('mousedown', function () {
        let interval   = setInterval(function () {
            size_changer(1, 0);
        }, speed);
        this.onmouseup = function () {
            clearInterval(interval);
        };
        interv         = interval;
    });
    Id('right').addEventListener('touchstart', function () {
        let interval    = setInterval(function () {
            size_changer(1, 0);
        }, speed);
        this.ontouchend = function () {
            clearInterval(interval);
        };
        interv          = interval;
    });


    Id('up').addEventListener('mousedown', function () {
        let interval   = setInterval(function () {
            size_changer(0, -1);
        }, speed);
        this.onmouseup = function () {
            clearInterval(interval);
        };
        interv         = interval;
    });
    Id('up').addEventListener('touchstart', function () {
        let interval    = setInterval(function () {
            size_changer(0, -1);
        }, speed);
        this.ontouchend = function () {
            clearInterval(interval);
        };
        interv          = interval;
    });
    Id('down').addEventListener('mousedown', function () {
        let interval   = setInterval(function () {
            size_changer(0, 1);
        }, speed);
        this.onmouseup = function () {
            clearInterval(interval);
        };
        interv         = interval;
    });
    Id('down').addEventListener('touchstart', function () {
        let interval    = setInterval(function () {
            size_changer(0, 1);
        }, speed);
        this.ontouchend = function () {
            clearInterval(interval);
        };
        interv          = interval;
    });
    buttons = 1;
}

function gallery_numbers(action, number) {
    let popup, img;
    if ((popup = Cls('popup')[0]) && (img = Tag(popup, 'img')[0])) {
        let gallery = Cls('layout')[0].childNodes;
        for (i = 0; i < gallery.length; i++) {
            if (Tag(gallery[i], 'img')[0].src === img.src) {
                if (action === 'comment')
                    gallery[i].getElementsByClassName('icons')[0].childNodes[1].innerHTML =
                        parseInt(gallery[i].getElementsByClassName('icons')[0].childNodes[1].innerHTML) + number;
                else if (action === 'like')
                    gallery[i].getElementsByClassName('icons')[0].childNodes[0].innerHTML =
                        parseInt(gallery[i].getElementsByClassName('icons')[0].childNodes[0].innerHTML) + number;
            }
        }
    }

}

window.onclick = function (event) {
    if (event.target.className === 'popup' ||
        event.target.id === 'no' ||
        event.target.id === 'close') {
        remove_popup();
    }
    if (event.target.id === 'database') {
        window.location.href = "http://localhost:8080/setup";
    }
    if (event.target.id === 'main') {
        window.location.href = "http://localhost:8080";
    }
    if (event.target.id === 'forgot') {
        create_forgot_form();
    }
    if (event.target.id === 'back-form') {
        Cls('form-body')[0].removeAttribute('style');
        Cls('form-body')[0].innerHTML = form;
        DTag('input')[0].addEventListener('focus', Focus1);
        DTag('input')[1].addEventListener('focus', Focus1);
    }
    if (event.target.id === 'change') {
        var inputs     = DTag('input'),
            parameters = {
                'login': ((document.location.href.split('/'))[3].split('='))[1],
                'code': ((document.location.href.split('/'))[3].split('='))[2]
            };
        for (var i = 0, j = 0; i < inputs.length; i++) {
            if (Tag(inputs[i].parentNode, 'span')[0].style.visibility === 'hidden' ||
                Tag(inputs[i].parentNode, 'span')[0].style.visibility === '') {
                Tag(inputs[i].parentNode, 'p')[0].innerHTML     = arr2[inputs[i].getAttribute("placeholder")];
                Tag(inputs[i].parentNode, 'p')[0].style.display = 'block';
                j++;
            }
            if (inputs[i].getAttribute("placeholder") === 'New Password')
                parameters['password'] = inputs[i].value;
        }
        if (j === 0) {
            xml.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    message('Password changed');
                    Cls('form-body')[0].childNodes[0].remove();
                }
            };
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=save&action=change password&parameter=" + JSON.stringify(parameters));
        }
    }
    if (event.target.id === 'reset') {
        var input = Tag(Cls('form-body')[0], 'input')[0],
            p     = Tag(input.parentNode, 'p')[0];
        if (input.value && p.style.display === 'none') {
            xml.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    message('To reset password check your mail');
                }
            };
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=input&action=reset password&parameter=" + input.value);
        } else {
            if (!p.innerHTML)
                p.innerHTML = arr2['Email'];
            p.style.display = 'block';
        }
    }
    if (event.target.id === 'session') {
        if (Id('session').title === 'Log In') {
            change_display([[[SCls('form-body'), Sti('photos')], ['block']],
                [[SCls('layout'), Sti('session')], ['none']]]);
            mozilla_kostyl();
        } else {
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=status&action=log out&parameter=0");
            window.location.href = "http://localhost:8080";
        }
    }
    if (event.target.id === 'photos') {
        if (name) {
            xml.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    if (this.responseText === 'logged') {
                        change_display([[[SCls('layout')], ['flex']],
                            [[Sti('photos'), SCls('edit'), SCls('form-body')], ['none']],
                            [[Sti('add'), Sti('settings')], ['block']]]);
                        mozilla_kostyl();
                    } else {
                        window.location.href = "http://localhost:8080";
                    }
                }
            };
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=status&action=log in status&parameter=" + name);
        } else {
            change_display([[[SCls('layout')], ['flex']],
                [[Sti('photos'), SCls('form-body')], ['none']],
                [[Sti('session')], ['block']]]);
            mozilla_kostyl();
        }
    }
    if (event.target.id === 'verify') {
        setTimeout(function () {
            var inputs     = DTag('input'),
                parameters = {};
            for (var i = 0, j = 0; i < inputs.length; i++) {
                if (Tag(inputs[i].parentNode, 'span')[0].style.visibility !== 'visible') {
                    Tag(inputs[i].parentNode, 'p')[0].style.display = 'block';
                    j++;
                }
                if (inputs[i].getAttribute("placeholder") === 'Login')
                    parameters['login'] = inputs[i].value;
                else if (inputs[i].getAttribute("placeholder") === 'Password')
                    parameters['password'] = inputs[i].value;
                else if (inputs[i].getAttribute("placeholder") === 'Email')
                    parameters['email'] = inputs[i].value;
            }

            if (j === 0) {
                xml.onreadystatechange = function () {
                    if (this.readyState === 4 && this.status === 200) {
                        message('Activation was sent to your email');
                    }
                };
                xml.open('post', 'index.php', true);
                xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
                xml.send("operation=save&action=create user&parameter=" + JSON.stringify(parameters));
            }
        }, 1000);
    }
    if (event.target.id === 'create-user') {
        create_user_form();
    }
    if (event.target.id === 'login') {
        var user = {
            'login': DTag('input')[0].value,
            'password': DTag('input')[1].value
        };
        if (user['login'].length >= 6 && user['login'].length <= 16 &&
            /^\w+$/.test(user['login']) && user['password'].length >= 8 &&
            /^\w+$/.test(user['password'])) {
            xml.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    if (this.responseText === 'no')
                        error();
                    else {
                        window.location.href = "http://localhost:8080/" + this.responseText;
                    }
                }
            };
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=input&action=log in&parameter=" + JSON.stringify(user));
        } else {
            error();
        }
    }
    if (event.target.id === 'settings') {
        if (name) {
            xml.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    if (this.responseText === 'logged') {
                        change_display([[[Sti('settings'), SCls('edit'), SCls('layout')], ['none']],
                            [[SCls('form-body'), Sti('add'), Sti('photos')], ['block']]]);
                        mozilla_kostyl();
                    } else {
                        window.location.href = "http://localhost:8080";
                    }
                }
            };
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=status&action=log in status&parameter=" + name);
        }
    }
    if (event.target.id === 'resend') {
        var parameters         = {
            'login': name,
            'email': Cls('form-body')[0].childNodes[5].childNodes[0].innerHTML
        };
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                var cells = Cls('form-body')[0].childNodes;
                cells[0].childNodes[0].classList.remove('redt');
                cells[0].childNodes[0].innerHTML = 'Activation was sent';
                cells[1].remove();

            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=save&action=resend&parameter=" + JSON.stringify(parameters));
    }
    if (event.target.id === 'on' ||
        event.target.id === 'off') {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                var resp      = this.responseText,
                    but       = Id(resp);
                but.id        = resp === 'on' ? 'off' : 'on';
                but.innerHTML = resp === 'on' ? 'OFF' : 'ON';
                but.classList.remove(resp === 'on' ? 'green' : 'red');
                but.classList.add(resp === 'on' ? 'red' : 'green');
                but.parentNode.childNodes[0].innerHTML = 'Notification are ' + resp;
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=save&action=" + event.target.id + "&parameter=" + name);
    }
    if (event.target.id === 'change-mail') {
        var cells = Cls('form-body')[0].childNodes;
        for (var i = 0; i < cells.length; i++) {
            if (cells[i] === Id('change-mail').parentNode) {
                change_mail_form(cells[i]);
                break;
            }
        }
    }
    if (event.target.id === 'cancel') {
        cancel_function();
    }
    if (event.target.id === 'confirm') {
        if (DTag('input')[0].value !== '' && DTag('input')[1].value !== '') {
            var parameters         = {
                'login': name,
                'password': DTag('input')[1].value,
                'email': DTag('input')[0].value
            };
            xml.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    if (this.responseText === 'no') {
                        Tag(Id('confirm').parentNode, 'p')[0].style.display = 'block';
                    } else {
                        cancel_function();
                        var cells = Cls('form-body')[0].childNodes;
                        for (var i = 0; i < cells.length; i++) {
                            if (cells[i].childNodes[0].className === 'message up') {
                                cells[i].childNodes[0].innerHTML = this.responseText;
                                break;
                            }
                        }
                    }
                }
            };
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=save&action=change email&parameter=" + JSON.stringify(parameters));
        }
    }
    if (event.target.id === 'delete-user') {
        var cells = Cls('popup')[0].childNodes[0].childNodes,
            par   = crE('p'),
            but   = crE('button');

        par.innerHTML   = 'Delete your account,<br> all your photos<br>and comments?';
        par.style.color = '#000';
        but.innerHTML   = 'YES';
        but.setAttribute('id', 'yes');
        but.classList.add('green');
        but.classList.add('smaller');

        cells[0].appendChild(par);
        cells[1].appendChild(but);

        but           = crE('button');
        but.innerHTML = 'NO';
        but.setAttribute('id', 'no');
        but.classList.add('red');
        but.classList.add('smaller');
        cells[1].appendChild(but);

        SCls('popup').display                             = 'flex';
        Cls('popup')[0].childNodes[0].style.flexDirection = 'column';
    }
    if (event.target.id === 'yes') {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                window.location.href = "http://localhost:8080/";
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=save&action=delete user&parameter=" + name);
    }
    if (event.target.id === 'add') {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                var data = JSON.parse(this.responseText);
                if (data['activation'] === 'yes') {
                    change_display([[[SCls('edit')], ['flex']],
                        [[Sti('add'), SCls('layout'), SCls('form-body')], ['none']],
                        [[Sti('photos'), Sti('settings')], ['block']]]);
                    photo_form(data['photos'], data['super']);
                }
                else {
                    popup_text('Your account is not activated');
                }
                mozilla_kostyl();
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=status&action=photos data&parameter=" + name);
    }
    if (event.target.id === 'right2') {
        change_display([[[Sti('right2'), SCls('col-box')], ['none']],
            [[Sti('left2')], ['flex']], [[SCls('img-col')], ['block']]]);
        med = window.matchMedia('(min-width: 601px) and (max-width: 650px), (min-width: 950px)');
        med.addListener(width_event);

    }
    if (event.target.id === 'left2') {
        remove_style([Id('right2'), Id('left2'), Cls('col-box')[0], Cls('img-col')[0]]);
        med.removeListener(width_event);
    }
    if (/super[0-9]{1,2}/.test(event.target.id)) {
        back_operations('super-remove');
        img_remove();
        event.target.parentNode.style.background = 'rgba(0, 0, 0, 0.15)';

        scale      = (200 / 224) * 100;
        last_super = event.target.parentNode;
        operation  = 'super-back';
        img_add(event.target);
        change_display([[[Sti('next')], ['block']],
            [[SCls('arrows'), Cls('arrows')[1].style], ['flex']]]);

        if (!buttons)
            buttons_events();

        Id('super').addEventListener('touchstart', function (e) {
            x = e.targetTouches[0].clientX;
            y = e.targetTouches[0].clientY;
        });
        Id('super').addEventListener('touchend', function (e) {
            var t_x           = move.targetTouches[0].clientX,
                t_y           = move.targetTouches[0].clientY;
            Sti('super').left = (parseInt(Sti('super').left) + (t_x - x)) + 'px';
            Sti('super').top  = (parseInt(Sti('super').top) + (t_y - y)) + 'px';
            x                 = y = 0;
        });
        Id('super').addEventListener('touchmove', function (e) {
            move              = e;
            var t_x           = e.targetTouches[0].clientX,
                t_y           = e.targetTouches[0].clientY;
            Sti('super').left = (parseInt(Sti('super').left) + (t_x - x)) + 'px';
            Sti('super').top  = (parseInt(Sti('super').top) + (t_y - y)) + 'px';
            x                 = e.targetTouches[0].clientX;
            y                 = e.targetTouches[0].clientY;
        });
    }
    if (event.target.id === 'webcam') {
        if (navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
            navigator.mediaDevices.getUserMedia({video: true}).then(function (stream) {
                operation = 'webcam-back';
                dest      = 'web';
                webstream = stream;
                vid       = Id('video');
                vid.src   = window.URL.createObjectURL(stream);
                vid.play();
                change_display([[[Sti('webcam'), Sti('upload')], ['none']],
                    [[Sti('video')], ['block']],
                    [[SCls('buttons'), SCls('super-img')], ['flex']]]);

            }).catch(function (error) {
                if (error.name === 'PermissionDeniedError' ||
                    error.name === 'NotAllowedError') {
                    popup_text('Camera is not allowed <br>in browser settings');
                }
            });
        }
    }
    if (event.target.id === 'back-capture') {
        if (operation === 'webcam-back') {
            back_operations(operation);
        } else if (operation === 'super-back') {
            back_operations('super-remove');
            back_operations(operation);
            operation = dest === 'web' ? 'webcam-back' : 'upload-back';
        } else if (operation === 'post-back') {
            if (dest === 'web') {
                change_display([[[Sti('video')], ['block']]]);
                remove_style([Id('canvas')]);
            }
            change_display([[[Sti('next'), Sti('super')], ['block']],
                [[SCls('super-img'), SCls('arrows'), Cls('arrows')[1].style], ['flex']]]);
            remove_style([Id('post')]);
            back_operations(operation);
            operation = 'super-back';
        } else if (operation === 'upload-back') {
            back_operations(operation);
        }
    }
    if (event.target.id === 'next') {
        if (Id('super')) {
            back_operations('super-remove');
            remove_style([Id('next'), Cls('arrows')[0], Cls('arrows')[1]]);
            change_display([[[Sti('super'), SCls('super-img'), Sti('video')], ['none']],
                [[Sti('post'), Sti('canvas')], ['block']]]);
            operation = 'post-back';
            form_picture();
        }
    }
    if (event.target.id === 'post') {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                if (this.responseText === 'yes') {
                    window.location.reload();
                } else {
                    popup_text('You need to log in');
                }
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=save&action=image&parameter=" + JSON.stringify([name, data]));
    }
    if (event.target.id === 'upload') {
        (input = crE('input')).type = 'file';
        input.onchange = function () {
            let file = input.files[0], read = new FileReader();
            if (file.size > 10000000)
                popup_text('Upload limit 10mb');
            else if (file.type.split('/')[0] !== 'image')
                popup_text('This file is not image');
            else if (file.type !== '' &&
                file.type.split('/')[0] === 'image') {
                read.onload = function () {
                    operation  = 'upload-back';
                    dest       = 'file';
                    img        = new Image();
                    img.onload = function () {
                        Id('canvas').getContext('2d').drawImage(img, 0, 0, Id('canvas').width, Id('canvas').height);
                    };
                    img.src    = read.result;
                    change_display([[[Sti('webcam'), Sti('upload')], ['none']],
                        [[Sti('canvas')], ['block']],
                        [[SCls('buttons'), SCls('super-img')], ['flex']]]);
                };
                read.readAsDataURL(file);
            }
        };
        input.click();
    }
    if (event.target.className === 'icons') {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                comment_form(JSON.parse(this.responseText));
                med3 = window.matchMedia('(max-height: 500px), (max-height: 750px) and (max-width: 900px),' +
                    '(min-height: 750px) and (max-width: 900px) and (min-width: 565px)');
                med4 = window.matchMedia('(max-height : 550px) and (max-width : 565px)');
                med3.addListener(width_event2);
                med4.addListener(width_event3);
                width_event2(med3);
                width_event3(med4);
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=status&action=photo data&parameter=" +
            JSON.stringify([(Tag(event.target.parentNode, 'img')[0].src.split('/'))[5],
                Tag(event.target, 'p')[0].innerHTML]));
    }
    if (event.target.id === 'remove') {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                if (this.responseText === 'ok') {
                    gallery_numbers('comment', -1);
                    event.target.parentNode.remove();
                }
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=status&action=remove comment&parameter=" + event.target.parentNode.id);
    }
    if (/like[0-9]{1,9}/.test(event.target.id)) {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                if (this.responseText === 'no') {
                    remove_popup();
                    popup_text('Your account is not activated');
                } else {
                    let number = parseInt(event.target.parentNode.childNodes[0].innerHTML.split(': ')[1]),
                        text   = event.target.parentNode.childNodes[0];
                    if (this.responseText === 'insert') {
                        text.innerHTML         = 'Likes: ' + (number + 1);
                        event.target.innerHTML = 'Unlike';
                        event.target.classList.remove('blue');
                        event.target.classList.add('red');
                        gallery_numbers('like', 1);
                    } else {
                        text.innerHTML         = 'Likes: ' + (number - 1);
                        event.target.innerHTML = 'Like';
                        event.target.classList.remove('red');
                        event.target.classList.add('blue');
                        gallery_numbers('like', -1);
                    }
                }
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=save&action=like&parameter=" + event.target.id.substr(4));
    }
    if (event.target.id === 'down2') {
        change_display([[[Tag(Cls('popup')[0], 'img')[0].style, SCls('buts'), Sti('down2')], ['none']],
            [[SCls('comments'), SCls('likes')], ['flex']], [[Sti('up2')], ['block']]]);
        Cls('comments')[0].parentNode.style.height = '247px';
    }
    if (event.target.id === 'up2') {
        remove_style([Tag(Cls('popup')[0], 'img')[0], Cls('buts')[0], Cls('likes')[0]]);
        change_display([[[SCls('comments'), Sti('up2'), SCls('likes')], ['none']], [[Sti('down2')], ['block']]]);
        Cls('comments')[0].parentNode.style.height = 'auto';
    }
    if (event.target.id === 'download') {
        let dwn      = crE('a');
        dwn.href     = Tag(event.target.parentNode.parentNode, 'img')[0].src;
        dwn.download = 'photo.png';
        dwn.click();
    }
    if (event.target.id === 'comment') {
        if (parseInt(Id('count').innerHTML) >= 0 &&
            parseInt(Id('count').innerHTML) !== 400 &&
            /\S/.test(Tag(Cls('popup')[0], 'textarea')[0].value)) {
            let comment            = encodeURI(Tag(Cls('popup')[0], 'textarea')[0].value),
                pic                = (Tag(Cls('popup')[0], 'img')[0].src.split('/'))[5],
                param              = encodeURIComponent(JSON.stringify([pic, comment]));
            xml.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    if (this.responseText === 'no') {
                        remove_popup();
                        popup_text('Your account is not activated');
                    } else {
                        let com = Cls('comments')[0].childNodes,
                            div = crE('div'),
                            h5  = crE('h5'),
                            p1  = crE('p'),
                            but = crE('button'),
                            p2  = crE('p'),
                            jsn = JSON.parse(this.responseText),
                            txt;
                        for (i = 0; i < com.length; i++)
                            if (txt = Tag(com[i], 'textarea')[0])
                                break;
                        txt.value    = '';
                        div.id       = jsn.id;
                        h5.innerHTML = jsn.h5;
                        p1.innerHTML = decodeURI(jsn.p);
                        p2.classList.add('comments-date');
                        p2.innerHTML = jsn.date;
                        but.id       = but.innerHTML = 'remove';
                        but.classList.add('red');
                        but.classList.add('round');
                        div.appendChild(h5);
                        div.appendChild(p1);
                        div.appendChild(p2);
                        div.appendChild(but);
                        Cls('comments')[0].insertBefore(div, com[i]);
                        gallery_numbers('comment', 1);
                    }
                }
            };
            xml.open('post', 'index.php', true);
            xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xml.send("operation=save&action=add comment&parameter=" + param);
        }
    }
    if (event.target.id === 'delete-image') {
        SCls('answers').display = 'flex';
    }
    if (event.target.id === 'cancel-delete') {
        SCls('answers').display = 'none';
    }
    if (event.target.id === 'confirm-delete') {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                window.location.reload();
            }
        };
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=save&action=delete photo&parameter=" +
            (Tag(event.target.parentNode.parentNode, 'img')[0].src.split('/'))[5]);
    }
};

window.onmouseup = function (event) {
    if (event.target) {
        for (i = 0; i < interv + 1; i++) {
            clearInterval(i);
        }
    }
};

window.ontouchend = function (event) {
    if (event.target) {
        for (i = 0; i < interv + 1; i++) {
            clearInterval(i);
        }
    }
};


function load_more() {
    if (!scroll_load) {
        xml.onreadystatechange = function () {
            if (this.readyState === 4 && this.status === 200) {
                if (this.responseText !== 'no more photos') {
                    let arr    = JSON.parse(this.responseText),
                        layout = Cls('layout')[0],
                        div1, div2, img, p1, p2;
                    for (let i = 0; i < arr.length; i++) {
                        (div1 = crE('div')).classList.add('img-cell');
                        (img = crE('img')).src = 'view/photos/' + arr[i].name;
                        (div2 = crE('div')).classList.add('icons');
                        (p1 = crE('p')).innerHTML = arr[i].likes;
                        (p2 = crE('p')).innerHTML = arr[i].comments;
                        div2.appendChild(p1);
                        div2.appendChild(p2);
                        div1.appendChild(img);
                        div1.appendChild(div2);
                        layout.appendChild(div1);
                        icons_mouseover();
                        scroll_load = 0;
                    }
                } else {
                    Cls('layout')[0].onscroll = document.onscroll = null;
                }
            }
        };
        scroll_load            = 1;
        xml.open('post', 'index.php', true);
        xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xml.send("operation=get data&action=more photos&parameter=" + Cls('layout')[0].childNodes.length);
    }
}

function scroll_func(event) {
    if (Cls('layout')[0] && event.target === Cls('layout')[0]) {
        if (event.target.scrollTop + event.target.offsetHeight >= event.target.lastChild.offsetTop) {
            load_more();
        }
    } else if (event.target === document) {
        if (event.target.scrollingElement.scrollTop + window.innerHeight >= Cls('layout')[0].lastChild.offsetTop) {
            load_more();
        }
    }
}

if (Cls('layout')[0])
    Cls('layout')[0].onscroll = scroll_func;
document.onscroll = scroll_func;

mozilla_kostyl();
icons_mouseover();