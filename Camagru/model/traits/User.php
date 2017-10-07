<?php

    trait User {
        public function user_input($action, $parameter) {
            $users = $this->get_database('users', 0);
            if ($action === 'email validation') {
                if (filter_var($parameter, FILTER_VALIDATE_EMAIL)) {
                    if ($users) {
                        foreach ($users as $user) {
                            if ($parameter == $user['email']) {
                                echo 'no';
                                return 0;
                            }
                        }
                    }
                    echo 'true';
                } else
                    echo 'false';
            } elseif ($action === 'login validation') {
                if ($users) {
                    foreach ($users as $user) {
                        if ($parameter == $user['login']) {
                            echo 'false';
                            return 0;
                        }
                    }
                }
                echo 'true';
            } elseif ($action === 'reset password') {
                $random = hash('whirlpool', mt_rand(100000000, 2147483647));
                $link = substr($random, 32, 16);
                $login = 0;
                foreach ($users as $user) {
                    if ($user['email'] === $parameter) {
                        $login = $user['login'];
                        break;
                    }
                }
                $_SESSION[$login . '_reset'] = $link;

                $message = <<<TXT
To reset password follow this link http://localhost:8080/reset={$login}={$link}
TXT;
                $header = "Content-type: text/html; charset=utf-8 \r\nFrom: Camagru <camagru@unit.ua> \r\n";
                mail($parameter, 'Reset Password', $message, $header);
            } elseif ($action === 'log in') {

                $json = json_decode($parameter, true);
                $json['password'] = hash('whirlpool', $json['password']);
                if ($users) {
                    foreach ($users as $user) {
                        if ($user['login'] === $json['login'] &&
                            $user['password'] === $json['password']) {
                            $_SESSION['login'] = $user['login'];

                            echo $user['login'];
                            return 0;
                        }
                    }
                    echo 'no';
                } else {
                    echo 'no';
                }
            }

            return 0;
        }

        public function user_status($action, $parameter) {
            $users = $this->get_database('users', 0);
            if ($action === 'log in status') {
                if ($parameter === $_SESSION['login']) {
                    echo 'logged';
                } else {
                    echo 'no';
                }
            } elseif ($action === 'log out') {
                unset($_SESSION['login']);
            } elseif ($action === 'activation status' || $action === 'remove comment' ||
                $action === 'photos data' || $action === 'photo data') {
                if ($action === 'photo data') {
                    $json = json_decode($parameter);
                    $author = $this->get_database('author data', $json[0]);
                    $author['date'] = date('j F \a\t G:i', $author['date']);
                    $data = call_user_func_array(function ($arr) {
                        $len = count($arr);
                        if ($len === 0)
                            return false;
                        for ($i = 0; $i < $len; $i++) {
                            $arr[$i]['date'] = date('j F \a\t G:i', $arr[$i]['date']);
                        }
                        return $arr;
                    }, [$this->get_database('photo comments', $json[0])]);
                }
                if (isset($_SESSION['login'])) {
                    foreach ($users as $user) {
                        if ($_SESSION['login'] === $user['login']) {
                            if ($action === 'activation status') {
                                echo $user['activation'];
                            } elseif ($action === 'photos data') {
                                $super = call_user_func(function () {
                                    for ($i = 0, $j = 1; $i < 62; $i++, $j++)
                                        $arr[$i] = 'super' . ($j <= 9 ? '0' : '') . $j . '.png';
                                    return $arr;
                                });
                                echo json_encode(['activation' => $user['activation'],
                                                  'photos'     => $this->get_database($parameter, 0),
                                                  'super'      => $super]);
                            } elseif ($action === 'photo data') {
                                echo json_encode(['author'   => $author,
                                                  'likes'    => ['liked'  => $this->get_database('likes data', $json[0]),
                                                                 'number' => $json[1],
                                                                 'id'     => $this->get_database('photo id', $json[0])],
                                                  'comments' => ['data' => $data,
                                                                 'form' => true],
                                                  'login'    => $_SESSION['login']]);
                            } elseif ($action === 'remove comment') {
                                $com_data = $this->get_database('comment data', $parameter);
                                if ($com_data['author'] === $_SESSION['login'] ||
                                    $com_data['login'] === $_SESSION['login']) {
                                    $this->manage_user('remove comment', $parameter);
                                    echo 'ok';
                                }
                            }
                            break;
                        }
                    }
                } elseif ($action === 'photo data') {
                    echo json_encode(['author'   => $author,
                                      'likes'    => ['number' => $json[1]],
                                      'comments' => ['data' => $data,
                                                     'form' => false],
                                      'login'    => false]);
                }
            }
        }

        public function manage_user($action, $parameter) {
            $con = $this->con;
            $users = $this->get_database('users', 0);

            $PDO = new PDO($con['db_dsn'], $con['db_user'], $con['db_password']);
            $header = "Content-type: text/html; charset=utf-8 \r\nFrom: Camagru <camagru@unit.ua> \r\n";
            $random = hash('whirlpool', mt_rand(100000000, 2147483647));
            $code = substr($random, 32, 8) . substr($random, 64, 16);

            if ($action == 'create user') {
                $statement = <<<QRY
INSERT INTO `users`(`user_id`, `login`, `activation`, `notification`, `password`, `email`)
VALUES (0, ?, ?, 'on', ?, ?)
QRY;
                $json = json_decode($parameter, true);
                $json['password'] = hash('whirlpool', $json['password']);
                $json['activation'] = $code;
                $exec_arr = [$json['login'], $json['activation'], $json['password'], $json['email']];
                $qry = $PDO->prepare($statement);
//                echo "redy 1\n";
                $qry->execute($exec_arr);
                $message = <<<TXT
Your login is: <strong>{$json['login']}</strong>.<br>
To make photos, like them and leave comments you need to activate your profile,<br>
to do this follow link http://localhost:8080/{$json['login']}={$json['activation']}
TXT;
                mail($json['email'], 'Activation', $message, $header);
            } elseif ($action == 'activation') {
                $PDO->exec("UPDATE `users` SET `activation`='yes' WHERE `login`='" . $parameter . "'");
            } elseif ($action == 'change password') {
                $json = json_decode($parameter, true);
                $json['password'] = hash('whirlpool', $json['password']);
                $PDO->exec("UPDATE `users` SET `password`='" .
                    $json['password'] . "' WHERE `login`='" . $json['login'] . "'");
            } elseif ($action == 'resend') {

                $arr = json_decode($parameter, true);

                $PDO->exec("UPDATE `users` SET `activation` = '" . $code . "' WHERE `users`.`login` = '" . $arr['login'] . "'");

                $message = <<<TXT
To activate your profile, follow this link http://localhost:8080/{$arr['login']}={$code}
TXT;
                mail($arr['email'], 'Activation', $message, $header);
            } elseif ($action == 'on' || $action == 'off') {
                $PDO->exec("UPDATE `users` SET `notification` = '" . $action . "' WHERE `users`.`login` = '" . $parameter . "'");
                echo $action;
            } elseif ($action == 'change email') {
                $arr = json_decode($parameter, true);
                $arr['password'] = hash('whirlpool', $arr['password']);

                if (filter_var($arr['email'], FILTER_VALIDATE_EMAIL)) {
                    foreach ($users as $user) {
                        if ($arr['email'] == $user['email']) {
                            echo 'no';
                            return 0;
                        }
                    }
                    foreach ($users as $user) {
                        if ($arr['login'] == $user['login'] &&
                            $arr['password'] == $user['password']) {
                            $PDO->exec("UPDATE `users` SET `email` = '" . $arr['email'] . "' WHERE `users`.`login` = '" . $arr['login'] . "'");
                            echo $arr['email'];
                            return 0;
                        }
                    }
                }
                echo 'no';
            } elseif ($action == 'image') {
                $json = json_decode($parameter);
                if ($json[0] === $_SESSION['login']) {
                    $data = str_replace('data:image/png;base64,', '', $json[1]);
                    $data = str_replace(' ', '+', $data);
                    $data = base64_decode($data);
                    $time = time();
                    $statement = <<<QRY
INSERT INTO `photos`(`photo_id`, `user_id`, `name`, `date`)
VALUES (0,(SELECT `user_id` FROM `users` WHERE `login`='$json[0]'),?,?)
QRY;
                    $exec_arr = [$time . '.png', $time];
                    $qry = $PDO->prepare($statement);
                    $qry->execute($exec_arr);
                    if (!file_exists('view/photos'))
                        mkdir('view/photos');
                    file_put_contents('view/photos/' . $time . '.png', $data);
                    echo 'yes';
                } else {
                    echo 'no';
                }
            } elseif ($action == 'remove comment') {
                $PDO->exec("DELETE FROM `comments` WHERE `comment_id` ='" . $parameter . "'");
            } elseif ($action == 'like') {
                if (isset($_SESSION['login'])) {
                    if ($PDO->query("SELECT `users`.`activation` FROM `users`" .
                            " WHERE `users`.`login` ='" . $_SESSION['login'] .
                            "'")->fetchAll(PDO::FETCH_COLUMN)[0] === 'yes') {
                        $user_id = $PDO->query("SELECT `user_id` FROM `users` WHERE `login` = '" .
                            $_SESSION['login'] . "'")->fetchAll(PDO::FETCH_COLUMN)[0];
                        if (empty($PDO->query("SELECT `likes`.`photo_id`, `likes`.`user_id` FROM `likes`" .
                            " WHERE `likes`.`photo_id` = " . $parameter .
                            " and `likes`.`user_id` = " . $user_id)->fetchAll(PDO::FETCH_COLUMN))) {
                            $PDO->exec("INSERT INTO `likes`(`photo_id`, `user_id`)" .
                                " VALUES (" . $parameter . "," . $user_id . ")");
                            echo 'insert';
                        } else {
                            $PDO->exec("DELETE FROM `likes` WHERE `likes`.`user_id` = " .
                                $user_id . " and `likes`.`photo_id` = " . $parameter);
                            echo 'drop';
                        }
                    } else
                        echo 'no';
                }
            } elseif ($action == 'add comment') {
                if (isset($_SESSION['login'])) {
                    if ($PDO->query("SELECT `users`.`activation` FROM `users`" .
                            " WHERE `users`.`login` ='" . $_SESSION['login'] .
                            "'")->fetchAll(PDO::FETCH_COLUMN)[0] === 'yes') {
                        $json = json_decode($parameter);
                        $json[1] = htmlentities($json[1]);
                        $data = $PDO->query("SELECT `t`.`notification`," .
                            " `t`.`email`, `t`.`photo_id`, `users`.`user_id` FROM" .
                            " (SELECT `users`.`notification`, `users`.`email`, `photos`.`photo_id`" .
                            " FROM `users` INNER JOIN `photos` ON `photos`.`user_id` = `users`.`user_id`" .
                            " WHERE `photos`.`name` = '" . $json[0] . "') as `t`" .
                            " JOIN `users` WHERE `users`.`login` = '" . $_SESSION['login'] .
                            "'")->fetchAll(PDO::FETCH_ASSOC)[0];
                        $time = time();
                        $statement = "INSERT INTO `comments`(`comment_id`, `photo_id`," .
                            " `user_id`, `comment`, `date`) VALUES (0,?,?,?,?)";
                        $exec_arr = [$data['photo_id'], $data['user_id'], $json[1], $time];
                        $qry = $PDO->prepare($statement);
                        $qry->execute($exec_arr);
                        if ($data['notification'] === 'on') {
                            $message = "There is a new comment under your photo";
                            mail($data['email'], 'Comment', $message, $header);
                        }
                        echo json_encode(['id'   => $PDO->lastInsertId(),
                                          'h5'   => $_SESSION['login'],
                                          'p'    => $json[1],
                                          'date' => date('j F \a\t G:i', $time)]);
                    } else
                        echo 'no';
                }
            } elseif ($action == 'delete photo') {
                if (isset($_SESSION['login'])) {
                    $data = $PDO->query("SELECT `users`.`login`, `photos`.`photo_id` as `id` FROM `photos`" .
                        " INNER JOIN `users` ON `photos`.`user_id` = `users`.`user_id`" .
                        " WHERE `photos`.`name` = '" . $parameter . "'")->fetchAll(PDO::FETCH_ASSOC)[0];
                    if ($_SESSION['login'] === $data['login']) {
                        $PDO->exec("DELETE `photos`, `comments`, `likes` FROM `photos`" .
                            " LEFT JOIN `comments` ON `comments`.`photo_id` = `photos`.`photo_id`" .
                            " LEFT JOIN `likes` ON `likes`.`photo_id` = `photos`.`photo_id`" .
                            " WHERE `photos`.`photo_id` = " . $data['id']);
                        shell_exec('rm view/photos/' . $parameter);
                    }
                }
            } elseif ($action == 'delete user') {
                if (isset($_SESSION['login'])) {
                    if (!empty($photos = $this->get_database('user photos', 0)))
                        foreach ($photos as $photo)
                            shell_exec('rm view/photos/' . $photo);
                    $PDO->exec("DELETE `users`, `photos`, `comments`, `likes` FROM `users`" .
                        " LEFT JOIN `photos` ON `photos`.`user_id` = `users`.`user_id`" .
                        " LEFT JOIN `comments` ON `comments`.`user_id` = `users`.`user_id`" .
                        " LEFT JOIN `likes` ON `likes`.`user_id` = `users`.`user_id`" .
                        " WHERE `users`.`login` = '" . $_SESSION['login'] . "'");
                    unset($_SESSION['login']);
                }
            }
            return 0;
        }
    }