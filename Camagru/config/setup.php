<?php

    if ($_SERVER['REQUEST_URI'] == '/config/setup.php') {
        header('Location: http://localhost:8080/setup');
        return ;
    }
