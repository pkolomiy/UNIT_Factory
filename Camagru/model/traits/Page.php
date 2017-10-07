<?php


    trait Page {

        public function what_page($uri_arr) {
            $uri_arr = explode("/", $uri_arr);
            $len = count($uri_arr);
            if ($len == 2) {
                return $this->get_page_name($uri_arr[1]);

            }
            return 0;
        }

        public function modify_user($login, $code) {
            if ($this->check_database() !== 'no') {
                $users = $this->get_database('users',0);
                if ($users) {
                    foreach ($users as $user) {
                        if ($user['login'] == $login) {
                            if ($user['activation'] == $code) {
                                $this->manage_user('activation', $login);
                                return 1;
                            }
                        }
                    }
                }
            }
            return 0;
        }

        public function get_page_name($page_name) {
            $page = explode("=", $page_name);
            if ($page_name === 'index.php') {
                return 1;
            } elseif ($page_name === '') {
                if (isset($_SESSION['login'])) {
                    return 2;
                } else {
                    return ['page'     => 'main',
                            'database' => $this->check_database(),
                            'login'    => 'no'];
                }
            } elseif (isset($_SESSION['login']) &&
                $page_name === $_SESSION['login']) {
                return ['page'     => 'main',
                        'database' => $this->check_database(),
                        'login'    => 'yes'];
            } elseif ($page_name === 'setup') {
                return ['page'        => 'setup',
                        'database'    => $this->check_database(),
                        'backup_list' => $this->manage_database('backup_list', 0)];
            } elseif ($page_name === '404') {
                return ['page' => '404'];
            } elseif (count($page) === 3 && $page[0] == 'reset' &&
                isset($_SESSION[$page[1] . '_reset'])) {
                if ($_SESSION[$page[1] . '_reset'] == $page[2]) {
                    unset($_SESSION[$page[1] . '_reset']);
                    return ['page' => 'reset'];
                }
            } elseif (count($page) === 2 &&
                $this->modify_user($page[0], $page[1]) === 1) {
                return ['page'  => 'activation',
                        'login' => $page[0]];
            }
            return 0;
        }

    }
