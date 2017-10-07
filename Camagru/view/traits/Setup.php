<?php

    trait Setup {

        public function setup_page($page_info) {

            $dom = $this->dom_var();
            $html = $this->html_var($dom);

            $html->head->addChild('title', 'Setup');
            $link = $html->head->addChild('link');
            $link->addAttribute('rel', 'stylesheet');
            $link->addAttribute('type', 'text/css');
            $link->addAttribute('href', 'view/styles/setup-page.css');

            $html->body->header->addChild('div');
            $html->body->header->div->addAttribute('id', 'return');
            $html->body->header->div->addChild('img')->addAttribute('src', 'view/img/back.png');
            $html->body->header->div->img->addAttribute('id', 'main');
            $html->body->header->addChild('p', 'Setup');

            $main = $html->xpath('//*[@class="main-body"]')[0];

            $main->addChild('div')->addAttribute('class', 'tabs');

            $tabs = $main->xpath('//*[@class="tabs"]')[0];
            $tabs->addChild('div')->addAttribute('id', 'beveled1');
            $tabs->addChild('div')->addAttribute('id', 'beveled2');
            $tabs->addChild('div', 'Database')->addAttribute('id', 'tab1');
            $tabs->addChild('div', 'Backup')->addAttribute('id', 'tab2');

            $main->addChild('div')->addAttribute('class', 'setup');

            $setup = $main->xpath('//*[@class="setup"]')[0];
            $setup->addChild('div')->addAttribute('class', 'cell');
            $setup->div->addChild('div')->addAttribute('id', 'window');

            $window = $setup->div->xpath('*[@id="window"]')[0];
            foreach ($page_info['backup_list'] as $name)
                if (strlen($name) > 1) {
                    $window->addChild('p', $name)->addChild('span', '&#10005;')->addAttribute('title', 'Delete backup');
                }

            $setup->div->addChild('div', 'Database ' . ($page_info['database'] === 'no' ? 'does not ' : '') . 'exist')->addAttribute('id', 'message');
            $setup->div->addChild('div')->addAttribute('class', 'cell');

            $cell = $setup->div->xpath('*[@class="cell"]')[0];
            $cell->addChild('div')->addAttribute('class', 'cell');
            $cell->addChild('div')->addAttribute('class', 'cell');
            $cell->div[0]->addChild('button', 'Install')->addAttribute('id', 'install');
            $cell->div[0]->addChild('button', 'Make backup')->addAttribute('id', 'make');
            $cell->div[1]->addChild('button', 'Delete')->addAttribute('id', 'delete');
            $cell->div[1]->addChild('button', 'Restore from backup')->addAttribute('id', 'restore');

            $main->addChild('div')->addAttribute('id', 'sure');

            $sure = $main->xpath('//*[@id="sure"]')[0];

            $sure->addChild('p', 'Are you sure?');
            $sure->addChild('button', 'Yes')->addAttribute('id', 'yes');
            $sure->addChild('button', 'No')->addAttribute('id', 'no');

            $script = $html->body->addChild('script');
            $script->addAttribute('language', 'javascript');
            $script->addAttribute('type', 'text/javascript');
            $script->addAttribute('src', 'view/javascript/setup.js');
            return (dom_import_simplexml($html)->ownerDocument)->saveHTML();
        }
    }