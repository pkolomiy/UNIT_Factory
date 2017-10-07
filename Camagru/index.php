<?php
    require_once 'controller/Controller.php';

    if (array_key_exists('operation', $_POST))
        (new Controller)->operations();
    else
        (new Controller)->page();
