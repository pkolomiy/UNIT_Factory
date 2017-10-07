<?php

    spl_autoload_register(function ($name) {
        if (file_exists('view/' . $name . '.php'))
            require_once 'view/' . $name . '.php';
        elseif (file_exists('view/traits/' . $name . '.php'))
            require_once 'view/traits/' . $name . '.php';
        elseif (file_exists('model/' . $name . '.php'))
            require_once 'model/' . $name . '.php';
        elseif (file_exists('model/traits/' . $name . '.php'))
            require_once 'model/traits/' . $name . '.php';
    });

    class Controller {

        protected $con;
        use Model, View;

        public function __construct() {
            require 'config/database.php';
            $this->con['global_dsn'] = $DSN;
            $this->con['global_user'] = $USER;
            $this->con['global_password'] = $PASSWORD;
            $this->con['db_dsn'] = $DB_DSN;
            $this->con['db_user'] = $DB_USER;
            $this->con['db_password'] = $DB_PASSWORD;
        }

        public function page() {
            date_default_timezone_set('Europe/Kiev');
            session_start();
            if (array_key_exists('uri', $_POST)) {
                $page_info = $this->what_page($_POST['uri']);
                $page_info['ajax'] = 'yes';
                unset($_POST['uri']);
            } else {
                $page_info = $this->what_page($_SERVER['REQUEST_URI']);
            }
            if ($page_info === 0)
                header('Location: http://localhost:8080/404');
            elseif ($page_info === 1)
                header('Location: http://localhost:8080/');
            elseif ($page_info === 2)
                header('Location: http://localhost:8080/' . $_SESSION['login']);
            $html = $this->get_html($page_info);
            echo $html;
        }

        public function operations() {
            date_default_timezone_set('Europe/Kiev');
            session_start();
            if ($_POST['operation'] == 'manage_database') {
                $this->manage_database($_POST['action'], $_POST['parameter']);
            } elseif ($_POST['operation'] == 'input') {
                $this->user_input($_POST['action'], $_POST['parameter']);
            } elseif ($_POST['operation'] == 'save') {
                $this->manage_user($_POST['action'], $_POST['parameter']);
            } elseif ($_POST['operation'] == 'status') {
                $this->user_status($_POST['action'], $_POST['parameter']);
            } elseif ($_POST['operation'] == 'get data') {
                $this->get_database($_POST['action'], $_POST['parameter']);
            }
        }
    }