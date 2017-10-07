function create_user_form() {
    form                          = Cls('form-body')[0].innerHTML;
    Cls('form-body')[0].innerHTML = '';
    for (var i = 0; i !== 6; i++) {
        var div   = crE('div'),
            input = crE('input'),
            but   = crE('button'),
            par   = crE('p'),
            span  = crE('span');
        if (i === 5) {
            but.innerHTML = 'Create';
            but.setAttribute('id', 'verify');
            but.classList.add('green');
            div.appendChild(but);
        }
        else if (i === 0) {
            but.innerHTML = 'Back';
            but.setAttribute('id', 'back-form');
            but.classList.add('blue');
            div.appendChild(but);
        }
        else {
            input.setAttribute('placeholder', arr[i - 1][0]);
            input.setAttribute('type', arr[i - 1][1]);
            input.style.width = '200px';
            input.addEventListener('blur', onBlur);
            input.addEventListener('focus', onFocus);
            par.classList.add('warn');
            par.innerHTML = arr2[arr[i - 1][0]];
            div.appendChild(input);
            span.classList.add('ok');
            span.innerHTML = '&#10004;';
            div.appendChild(span);
            div.appendChild(par);
        }
        div.setAttribute('class', 'cell');
        div.style.flexWrap = 'wrap';

        Cls('form-body')[0].appendChild(div);
    }
}

function create_forgot_form() {
    form                          = Cls('form-body')[0].innerHTML;
    Cls('form-body')[0].innerHTML = '';
    for (var i = 0; i < 3; i++) {
        var div   = crE('div'),
            input = crE('input'),
            but   = crE('button'),
            par   = crE('p');
        if (i === 0) {
            but.innerHTML = 'Back';
            but.setAttribute('id', 'back-form');
            but.classList.add('blue');
            div.appendChild(but);
        } else if (i === 1) {
            input.setAttribute('placeholder', 'Your Email');
            input.setAttribute('type', 'email');
            input.style.width = '200px';
            input.addEventListener('blur', onBlur);
            input.addEventListener('focus', onFocus);
            par.classList.add('warn');
            div.style.flexWrap = 'wrap';
            div.appendChild(input);
            div.appendChild(par);
        } else {
            but.innerHTML = 'Reset password';
            but.setAttribute('id', 'reset');
            but.classList.add('smaller');
            but.classList.add('green');
            div.appendChild(but);
        }
        div.setAttribute('class', 'cell');
        Cls('form-body')[0].appendChild(div);
    }
}

function create_reset_form() {
    var cells = Cls('form-body')[0].childNodes;
    for (var i = 0; i < cells.length; i++) {
        var input = crE('input'),
            but   = crE('button'),
            par   = crE('p'),
            span  = crE('span');
        if (i === 2) {
            but.innerHTML = 'Change password';
            but.setAttribute('id', 'change');
            but.classList.add('green');
            but.classList.add('smaller');
            cells[i].appendChild(but);
        } else {
            input.setAttribute('placeholder', i === 0 ?
                'New Password' : 'Repeat New Password');
            input.setAttribute('type', 'password');
            input.style.width = '200px';
            input.addEventListener('blur', onBlur);
            input.addEventListener('focus', onFocus);
            par.classList.add('warn');
            span.classList.add('ok');
            span.innerHTML          = '&#10004;';
            cells[i].style.flexWrap = 'wrap';
            cells[i].appendChild(input);
            cells[i].appendChild(span);
            cells[i].appendChild(par);
        }
    }
}

function change_mail_form(cell) {


    for (var i = 0; i < 3; i++) {
        var div   = crE('div'),
            input = crE('input'),
            but   = crE('button');
        div.setAttribute('class', 'cell');

        if (i === 0) {
            but.innerHTML = 'Cancel';
            but.setAttribute('id', 'cancel');
            but.classList.add('blue');
            but.classList.add('tiny');
            div.appendChild(but);
        } else if (i === 1 || i === 2) {
            input.setAttribute('placeholder', (i === 1 ? 'New Email' : 'Password'));
            input.setAttribute('type', (i === 1 ? 'email' : 'password'));
            input.addEventListener('focus', Focus2);
            div.appendChild(input);
            cell.style.flexWrap = 'wrap';
        }
        cell.parentNode.insertBefore(div, cell);
    }
    Id('change-mail').innerHTML = 'Confirm';
    Id('change-mail').classList.remove('smaller');
    Id('change-mail').id = 'confirm';
}

function photo_form(photos, sup) {
    var ed = Cls('edit')[0], div, pb, si, img, cap, buts,
        ico, elm, tmp, tmp2, but, ars;
    if (ed.innerHTML === '') {
        for (var i = 0; i < 4; i++) {
            div = crE('div');
            img = crE('img');

            if (i === 0) {
                div.classList.add('col-box');
                (pb = crE('div')).classList.add('photo-box');
                (cap = crE('div')).classList.add('capture');
                for (var j = 0; j < 4; j++) {
                    tmp = j ? ( j === 1 ? 'upload' :
                        (j === 2 ? 'video' : 'canvas')) : 'webcam';
                    if (j < 2) {
                        (ico = crE('div')).classList.add('ico');
                        (img = crE('img')).id = tmp;
                        img.src   = 'view/img/' + tmp + '.png';
                        img.title = j ? 'Upload File' : 'Use Webcam';
                        ico.appendChild(img);
                        cap.appendChild(ico);
                    } else {
                        (elm = crE(tmp)).id = tmp;
                        if (j === 2)
                            elm.autoplay = true;
                        elm.width  = 533;
                        elm.height = 400;
                        cap.appendChild(elm);
                    }
                }
                (buts = crE('div')).classList.add('buttons');
                tmp = [['back-capture', 'Back', 'blue'],
                    ['next', 'Next', 'green'],
                    ['post', 'Post', 'green']];
                for (j = 0; j < tmp.length; j++) {
                    but           = crE('button');
                    but.id        = tmp[j][0];
                    but.innerHTML = tmp[j][1];
                    but.classList.add(tmp[j][2]);
                    buts.appendChild(but);
                    if (!j) {
                        tmp2 = [[['left', '&#8592;'],
                            ['increase', '&#8600;'],
                            ['right', '&#8594;']],
                            [['up', '&#8593;'],
                                ['reduce', '&#8598;'],
                                ['down', '&#8595;']]];
                        for (var k = 0; k < 2; k++) {
                            (ars = crE('div')).classList.add('arrows');
                            for (var l = 0; l < 3; l++) {
                                but           = crE('button');
                                but.id        = tmp2[k][l][0];
                                but.innerHTML = tmp2[k][l][1];
                                but.classList.add('purple');
                                but.classList.add('round');
                                ars.appendChild(but);
                            }
                            buts.appendChild(ars);
                        }
                    }
                }
                (si = crE('div')).classList.add('super-img');
                for (j = 0; j < sup.length; j++) {
                    (ico = crE('div')).classList.add('ico');
                    (img = crE('img')).id = sup[j].replace(/\.png$/, '');
                    img.src = 'view/super/' + sup[j];
                    ico.appendChild(img);
                    si.appendChild(ico);
                }
                pb.appendChild(cap);
                pb.appendChild(buts);
                div.appendChild(pb);
                div.appendChild(si);
            } else if (i && i < 3) {
                div.classList.add('ico');
                img.id  = i === 1 ? 'right2' : 'left2';
                img.src = 'view/img/' + img.id + '.png';
                div.appendChild(img);
            } else {
                div.classList.add('img-col');
                div.setAttribute("onmouseover", "this.style.overflowY='scroll'");
                div.setAttribute("onmouseout", "this.style.overflowY='hidden'");
                div.setAttribute("touchstart", "this.style.overflowY='scroll'");
                div.setAttribute("touchend", "this.style.overflowY='hidden'");
                for (j = 0; j < photos.length; j++) {
                    (ico = crE('div')).classList.add('img-cell');
                    (img = crE('img')).src = 'view/photos/' + photos[j];
                    ico.appendChild(img);
                    div.appendChild(ico);
                }
            }
            ed.appendChild(div);
        }
    }
}


function comment_form(object) {
    let div1, div2, div3, img, but, p1, p2, h5, txt,
        pop      = Cls('popup')[0].childNodes[0],
        owner    = object.login === object.author.login,
        author   = object.author,
        likes    = object.likes,
        comments = object.comments.data,
        form     = object.comments.form,
        cell1    = pop.childNodes[0],
        cell2    = pop.childNodes[1];

    pop.style.alignItems      = 'flex-start';
    cell1.style.flexDirection = cell2.style.flexDirection = 'column';
    cell2.style.height = '447px';
    for (let i = 0; i < 2; i++) {
        if (i === 0) {
            (div1 = crE('div')).classList.add('cell');
            (img = crE('img')).src = 'view/photos/' + author.name;
            div1.appendChild(img);
            if (owner) {
                (div2 = crE('div')).classList.add('answers');
                for (let j = 0; j < 2; j++) {
                    (but = crE('button')).classList.add('tiny');
                    but.classList.add(j ? 'red' : 'blue');
                    but.id        = (j ? 'confirm-' : 'cancel-') + 'delete';
                    but.innerHTML = j ? 'Delete Photo' : 'Cancel';
                    div2.appendChild(but);
                }
                div1.appendChild(div2);
            }
        } else {
            (div1 = crE('div')).classList.add('buts');
            (but = crE('button')).classList.add('tiny');
            but.classList.add('green');
            but.id        = 'download';
            but.innerHTML = 'Download';
            div1.appendChild(but);
            if (owner) {
                (but = crE('button')).classList.add('tiny');
                but.classList.add('red');
                but.id        = 'delete-image';
                but.innerHTML = 'Delete';
                div1.appendChild(but);
            }
        }
        cell1.appendChild(div1);
    }
    for (let i = 0; i < 4; i++) {
        if (i === 0) {
            (div1 = crE('div')).classList.add('likes');
            for (let j = 0; j < 2; j++) {
                div2 = crE('div');
                if (j === 0) {
                    (p1 = crE('p')).id = 'author';
                    p1.innerHTML       = author.login;
                    (p2 = crE('p')).id = 'load-date';
                    p2.classList.add('comments-date');
                    p2.innerHTML = author.date;
                    div2.appendChild(p1);
                    div2.appendChild(p2);
                } else {
                    (p1 = crE('p')).innerHTML = 'Likes: ' + likes.number;
                    div2.appendChild(p1);
                    if (form) {
                        (but = crE('button')).id = 'like' + likes.id;
                        but.classList.add(likes.liked ? 'red' : 'blue');
                        but.classList.add('tiny');
                        but.innerHTML = likes.liked ? 'Unlike' : 'Like';
                        div2.appendChild(but);
                    }
                }
                div1.appendChild(div2);
            }
        } else if (i === 1 || i === 2) {
            (div1 = crE('div')).classList.add('ico');
            (img = crE('img')).id = i === 1 ? 'up2' : 'down2';
            img.src = 'view/img/' + img.id + '.png';
            div1.appendChild(img);
        } else {
            (div1 = crE('div')).classList.add('comments');
            for (let k = 0; k < comments.length; k++) {
                (div2 = crE('div')).id = comments[k].id;
                (p1 = crE('p')).innerHTML = decodeURI(comments[k].comment);
                (h5 = crE('h5')).innerHTML = comments[k].author;
                (p2 = crE('p')).classList.add('comments-date');
                p2.innerHTML = comments[k].date;
                div2.appendChild(h5);
                div2.appendChild(p1);
                div2.appendChild(p2);
                if (owner || comments[k].author === object.login) {
                    (but = crE('button')).id = 'remove';
                    but.innerHTML = 'remove';
                    but.classList.add('red');
                    but.classList.add('round');
                    div2.appendChild(but);
                }
                div1.appendChild(div2);
            }
            if (form) {
                div2                          = crE('div');
                (txt = crE('textarea')).title = 'comment';
                txt.cols           = 20;
                txt.rows           = 5;
                (p1 = crE('p')).id = 'count';
                p1.innerHTML                      = 400;
                (div3 = crE('div')).style.display = 'flex';
                div3.style.justifyContent = 'center';
                div3.style.alignItems     = 'baseline';
                (but = crE('button')).id  = 'comment';
                but.innerHTML = 'Leave comment';
                but.classList.add('blue');
                but.classList.add('tiny');
                txt.onkeyup = function () {
                    let nbr = 400 - encodeURI(this.value).length;
                    if (nbr >= 0)
                        Sti('count').color = '#888';
                    if (nbr > 100)
                        Sti('count').visibility = 'hidden';
                    if (nbr < 100)
                        Sti('count').visibility = 'visible';
                    if (nbr < 0)
                        Sti('count').color = '#f00';
                    Id('count').innerHTML = nbr;
                };
                div2.appendChild(txt);
                div2.appendChild(p1);
                div3.appendChild(but);
                div1.appendChild(div2);
                div1.appendChild(div3);
            }
        }
        cell2.appendChild(div1);
    }
    SCls('popup').display = 'flex';

}























