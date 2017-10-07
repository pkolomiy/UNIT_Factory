<?php


    trait Database {
        public function check_database() {
            $result = false;
            $check = function ($con, $result) {
                try {
                    if ($result === 1045) {
                        $PDO = new PDO($con['global_dsn'], $con['global_user'], $con['global_password'],
                            array(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION));
                        return $PDO->exec("CREATE USER IF NOT EXISTS 'camagru-user'@'localhost'
                                IDENTIFIED by '111111';
                                GRANT ALL ON `camagru`.* TO 'camagru-user'@'localhost';
                                FLUSH PRIVILEGES;");
                    }
                    return new PDO($con['db_dsn'], $con['db_user'], $con['db_password'],
                        array(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION));
                } catch (PDOException $Exception) {
                    return $Exception->getCode();
                }
            };
            $result = $check($this->con, $result);
            if ($result === 1045)
                $result = $check($this->con, $result);
            if ($result === 0)
                $result = $check($this->con, $result);
            if ($result === 1049)
                return 'no';
            return $result;
        }

        public function create_database($action) {
            $con = $this->con;

            $table = <<<QRY
CREATE TABLE `users` (
`user_id` INT NOT NULL AUTO_INCREMENT,
`login` VARCHAR(255) NOT NULL,
`activation` VARCHAR(255) NOT NULL,
`notification` VARCHAR(255) NOT NULL,
`password` VARCHAR(255) NOT NULL,
`email` VARCHAR(255) NOT NULL,
PRIMARY KEY (`user_id`))
QRY;
            $photos = <<<QRY
CREATE TABLE `photos` (
`photo_id` INT NOT NULL AUTO_INCREMENT,
`user_id` INT NOT NULL,
`name` VARCHAR(255) NOT NULL,
`date` VARCHAR(255) NOT NULL,
PRIMARY KEY (`photo_id`))
QRY;

            $comments = <<<QRY
CREATE TABLE `comments` (
`comment_id` INT NOT NULL AUTO_INCREMENT,
`photo_id` INT NOT NULL,
`user_id` INT NOT NULL,
`comment` VARCHAR(8000) NOT NULL,
`date` VARCHAR(255) NOT NULL,
PRIMARY KEY (`comment_id`))
QRY;

            $likes = <<<QRY
CREATE TABLE `likes` (
`photo_id` INT NOT NULL,
`user_id` INT NOT NULL
)
QRY;

            $PDO = new PDO($con['global_dsn'], $con['global_user'], $con['global_password']);
            $PDO->exec(($action === 'install' ? "CREATE" : "DROP") . " DATABASE `camagru`;");
            if ($action === 'install') {
                $PDO = new PDO($con['db_dsn'], $con['db_user'], $con['db_password']);
                $PDO->exec($table);
                $PDO->exec($photos);
                $PDO->exec($comments);
                $PDO->exec($likes);
            }

        }

        public function get_database($info, $parameter) {
            $con = $this->con;

            $PDO = new PDO($con['db_dsn'], $con['db_user'], $con['db_password']);

            if ($info == 'users')
                return $PDO->query('SELECT * FROM `users`')->fetchAll(PDO::FETCH_ASSOC);
            elseif ($info == 'photos')
                return $PDO->query('SELECT * FROM `photos` ORDER BY `date` DESC')->fetchAll(PDO::FETCH_ASSOC);
            elseif ($info == 'comments')
                return $PDO->query('SELECT * FROM `comments` ORDER BY `date`')->fetchAll(PDO::FETCH_ASSOC);
            elseif ($info == 'likes')
                return $PDO->query('SELECT * FROM `likes`')->fetchAll(PDO::FETCH_ASSOC);
            elseif ($info == 'gallery')
                return $PDO->query("SELECT `L`.`name`, `L`.`likes`, `C`.`comments`" .
                    " FROM ( SELECT `photos`.`name`, COUNT(`likes`.`photo_id`) AS `likes`" .
                    " FROM `photos` LEFT JOIN `likes` ON `likes`.`photo_id`=`photos`.`photo_id`" .
                    " GROUP BY `photos`.`name`) as `L`" .
                    " JOIN ( SELECT `photos`.`name`, COUNT(`comments`.`photo_id`) AS `comments`" .
                    " FROM `photos` LEFT JOIN `comments` ON `comments`.`photo_id`=`photos`.`photo_id`" .
                    " GROUP BY `photos`.`name`) as `C` ON `L`.`name`=`C`.`name` ORDER BY `name` DESC" .
                    " LIMIT " . $parameter[0] . ", " . $parameter[1])->fetchAll(PDO::FETCH_ASSOC);
            elseif ($info == 'author data')
                return $PDO->query("SELECT `photos`.`name`, `photos`.`date`, `users`.`login`" .
                    " FROM `photos` INNER JOIN `users` ON `photos`.`user_id` = `users`.`user_id`" .
                    " WHERE `photos`.`name` = '" . $parameter . "'")->fetchAll(PDO::FETCH_ASSOC)[0];
            elseif ($info == 'likes data')
                return $PDO->query("SELECT COUNT(`likes`.`user_id`) as `likes` FROM `users`" .
                        " LEFT JOIN `likes` ON `likes`.`user_id` = `users`.`user_id`" .
                        " WHERE `users`.`login` = '" . $_SESSION['login'] . "' AND `likes`.`photo_id` =" .
                        " (SELECT `photos`.`photo_id` FROM `photos` WHERE `photos`.`name` = '" . $parameter .
                        "') GROUP BY `users`.`user_id`")->fetchAll(PDO::FETCH_COLUMN) === ['1'];
            elseif ($info == 'photo id')
                return $PDO->query("SELECT `photo_id` as `id` FROM `photos`" .
                    " WHERE `photos`.`name` = '" . $parameter . "'")->fetchAll(PDO::FETCH_COLUMN)[0];
            elseif ($info == 'photo comments')
                return $PDO->query("SELECT `users`.`login` as `author`, `comms`.`comment`," .
                    " `comms`.`id`, `comms`.`date` FROM (SELECT `comments`.`comment`, `comments`.`date`," .
                    " `comments`.`user_id`, `comments`.`comment_id` as `id` FROM `comments`" .
                    " WHERE `comments`.`photo_id` = ( SELECT `photos`.`photo_id` FROM `photos`" .
                    " WHERE `photos`.`name` = '" . $parameter . "' ) ORDER BY `comments`.`date` ASC)" .
                    " as `comms` INNER JOIN `users` ON `users`.`user_id` = `comms`.`user_id`")->fetchAll(PDO::FETCH_ASSOC);
            elseif ($info == 'user photos')
                return $PDO->query("SELECT `photos`.`name` FROM `photos` INNER JOIN `users` ON" .
                    " `photos`.`user_id` = `users`.`user_id` WHERE `users`.`login`='"
                    . $_SESSION['login'] . "'")->fetchAll(PDO::FETCH_COLUMN);
            elseif ($info == 'more photos') {
                $photos_count = $PDO->query("SELECT COUNT(`photos`.`name`) FROM `photos`")->fetchAll(PDO::FETCH_COLUMN)[0];
                $limit = $photos_count - $parameter >= 10 ? 10 : $photos_count - $parameter;
                if ($limit)
                    echo json_encode($this->get_database('gallery', [$parameter,$limit]));
                else
                    echo 'no more photos';
//                }
            } elseif ($info == 'comment data')
                return $PDO->query("SELECT `t`.`login`, `users`.`login`" .
                    " as `author` FROM(SELECT `photos`.`name`, `users`.`login` FROM `comments`" .
                    " INNER JOIN `photos` ON `comments`.`photo_id` = `photos`.`photo_id`" .
                    " INNER JOIN `users` ON `comments`.`user_id` = `users`.`user_id`" .
                    " WHERE `comments`.`comment_id` = " . $parameter . ") as `t` INNER JOIN `photos`" .
                    " ON `t`.`name` = `photos`.`name` INNER JOIN `users`" .
                    " ON `photos`.`user_id`= `users`.`user_id`")->fetchAll(PDO::FETCH_ASSOC)[0];
            elseif ($info == $_SESSION['login'])
                return $PDO->query("SELECT `name` FROM `users`" .
                    " INNER JOIN `photos` ON `users`.`user_id`=`photos`.`user_id`" .
                    " WHERE `users`.`login`='" . $info . "' ORDER BY `date` DESC")->fetchAll(PDO::FETCH_COLUMN);
            return 0;
        }

        public function manage_database($action, $parameter) {
            date_default_timezone_set('Europe/Kiev');
            if (!file_exists('model/backup'))
                mkdir('model/backup');

            if ($action === 'install' || $action === 'delete') {
                $this->create_database($action);
            } else if ($action === 'create backup') {
                shell_exec('~/Library/Containers/MAMP/mysql/bin/mysqldump' .
                    ' --user=root --password=123456 camagru > model/backup/backup_' .
                    date('Y-m-d_H:i:s') . '.sql');
                echo json_encode(explode("\n", `ls -1 model/backup/`));
            } else if ($action === 'backup_list') {
                return explode("\n", `ls -1 model/backup/`);
            } else if ($action === 'remove backup') {
                shell_exec('rm model/backup/' . $parameter);
            } else if ($action === 'restore') {
                if ($this->check_database() !== 'no')
                    $this->manage_database('delete', 0);
                $this->manage_database('install', 0);
                $PDO = new PDO($this->con['db_dsn'], $this->con['db_user'], $this->con['db_password']);
                $PDO->exec(file_get_contents('model/backup/' . $parameter));
            }
            return 0;
        }

    }