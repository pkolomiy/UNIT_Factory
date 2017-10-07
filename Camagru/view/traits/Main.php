<?php

    trait Main {

        public function main_page($page_info) {

            $dom = $this->dom_var();
            $html = $this->html_var($dom);

            $html->head->addChild('title', 'Camagru');

            $html = $page_info['database'] !== 'no' ?
                $this->build_body($html, $page_info) : $this->build_setup($html);

            $dom->importNode(dom_import_simplexml($html), true);
            return $dom->saveHTML();

        }

        public function build_body($html, $page_info) {

            $users = $this->get_database('users', 0);

            $names = [$page_info['login'] == 'yes' ? 'logout' : 'login',
                'settings', 'photos', 'add'];
            $titles = [$page_info['login'] == 'yes' ? 'Log Out' : 'Log In',
                'Settings', 'Gallery', 'Add Photo'];
            for ($i = 0; $i < 4; $i++) {
                $html->body->header->addChild('div');
                $html->body->header->div[$i]->addAttribute('class', 'ico');
                $html->body->header->div[$i]->addChild('img')->addAttribute('src', 'view/img/' . $names[$i] . '.png');
                $html->body->header->div[$i]->img->addAttribute('id', $i ? $names[$i] : 'session');
                $html->body->header->div[$i]->img->addAttribute('title', $titles[$i]);
                if ($i == 1)
                    $html->body->header->addChild('p', 'Camagru');
            }

            $html->body->addChild('div')->addAttribute('class', 'popup');
            $popup = $html->xpath('//*[@class="popup"]')[0];
            $popup->addChild('div')->addAttribute('class', 'cell');
            $popup->div->addChild('div')->addAttribute('class', 'cell');
            $popup->div->addChild('div')->addAttribute('class', 'cell');
            $popup->div->addChild('span', '&#10005;')->addAttribute('id', 'close');

            $mb = $html->xpath('//*[@class="main-body"]')[0];

            $mb->addChild('div')->addAttribute('class', 'form-body');
            $fm = $html->xpath('//*[@class="form-body"]')[0];


            if ($page_info['login'] == 'yes') {

                $mb->addChild('div')->addAttribute('class', 'edit');

                $user = call_user_func_array(function ($users, $login) {
                    foreach ($users as $user) {
                        if ($user['login'] == $login) return $user;
                    }
                    return 0;
                }, [$users, $_SESSION['login']]);
                $start = $user['activation'] == 'yes' ? 3 : 0;
                for ($i = $start; $i < 9; $i++) {
                    $fm->addChild('div')->addAttribute('class', 'cell');
                    $cell = !$start ? $fm->div[$i] : $fm->div[$i - 3];
                    if ($i == 0) {
                        $cell->addChild('p', 'Profile is not activated')->addAttribute('class', 'message redt');
                    } elseif ($i == 1 || $i == 6) {
                        if ($i == 6)
                            $cell->addChild('p', 'Error try again')->addAttribute('class', 'warn');
                        $but = $cell->addChild('button', $i == 1 ? 'Resend activation' : 'Change email');
                        $but->addAttribute('id', $i == 1 ? 'resend' : 'change-mail');
                        $but->addAttribute('class', ($i == 1 ? 'blue' : 'green') . ' smaller');
                    } elseif ($i == 2 || $i == 4 || $i == 7) {
                        $cell->addChild('div')->addAttribute('class', 'line');
                    } elseif ($i == 3) {
                        $nf = $user['notification'];
                        $cell->addChild('p', 'Notification are ' . $nf)->addAttribute('class', 'message');
                        $but = $cell->addChild('button', ($nf == 'on' ? 'OFF' : 'ON'));
                        $but->addAttribute('id', ($nf == 'on' ? 'off' : 'on'));
                        $but->addAttribute('class', ($nf == 'on' ? 'red' : 'green') . ' tiny');
                    } elseif ($i == 5) {
                        $cell->addChild('p', $user['email'])->addAttribute('class', 'message up');
                    } else {
                        $but = $cell->addChild('button', 'Delete user');
                        $but->addAttribute('id', 'delete-user');
                        $but->addAttribute('class', 'red smaller');
                    }
                }
            } else {
                for ($i = 0; $i < 6; $i++) {
                    $fm->addChild('div')->addAttribute('class', 'cell');
                    $cell = $fm->div[$i];
                    if ($i === 0 || $i === 1) {
                        $input = $cell->addChild('input');
                        $input->addAttribute('placeholder', $i ? 'Password' : 'Username');
                        $input->addAttribute('type', $i ? 'password' : 'text');
                    } elseif ($i === 2 || $i === 5) {
                        $but = $cell->addChild('button', $i == 2 ? 'Log in' : 'Create user');
                        $but->addAttribute('id', $i == 2 ? 'login' : 'create-user');
                        $but->addAttribute('class', $i == 2 ? 'blue' : 'green');
                    } elseif ($i === 4) {
                        for ($j = -1; $j < 2; $j++) {
                            $cell->addChild('div', $j ? '' : 'or')->
                            addAttribute('class', $j ? 'line' : 'cell');
                        }
                    } else
                        $cell->addChild('p', 'Forgot password?')->addAttribute('id', 'forgot');
                }
            }

            $mb->addChild('div')->addAttribute('class', 'layout');
            $layout = $html->xpath('//*[@class="layout"]')[0];

            $photos = $this->get_database('gallery', [0, 12]);
            for ($i = 0; $i < count($photos); $i++) {
                $layout->addChild('div')->addAttribute('class', 'img-cell');
                $cell = $layout->div[$i];
                $cell->addChild('img')->addAttribute('src', 'view/photos/' . $photos[$i]['name']);
                $cell->addChild('div')->addAttribute('class', 'icons');
                $cell->div->addChild('p', $photos[$i]['likes']);
                $cell->div->addChild('p', $photos[$i]['comments']);
            }

            return $html;
        }

        public function build_setup($html) {

            $html->body->header->addChild('p', 'Camagru');

            $html->xpath('//*[@class="main-body"]')[0]->
            addChild('div')->addAttribute('class', 'setup');
            $htm = $html->xpath('//*[@class="setup"]')[0];

            for ($i = 0; $i < 2; $i++) {
                $htm->addChild('div')->addAttribute('class', 'cell');
                $cell = $htm->div[$i];
                if ($i)
                    $cell->addChild('button', 'Install')->addAttribute('id', 'database');
                else {
                    $cell->addChild('img')->addAttribute('src', 'view/img/alert.png');
                    $cell->addChild('p', 'Database is not installed');
                }
            }

            return $html;
        }
    }
