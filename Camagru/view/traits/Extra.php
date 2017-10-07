<?php

    trait Extra {

        public function lost_page() {

            $dom = $this->dom_var();
            $html = $this->html_var($dom);

            $html->head->addChild('title', 'You are lost');

            $div = $html->body->header->addChild('div');
            $div->addAttribute('id', 'return');
            $div->addChild('img')->addAttribute('src', 'view/img/back.png');
            $div->img->addAttribute('id', 'main');

            $html->body->header->addChild('p');

            unset($html->body->div[1]);

            $dom->importNode(dom_import_simplexml($html), true);

            return $dom->saveHTML();
        }

        public function activation_page($page_info) {
            $dom = $this->dom_var();
            $html = $this->html_var($dom);

            $html->head->addChild('title', 'Activate');

            $div = $html->body->header->addChild('div');
            $div->addAttribute('id', 'return');
            $div->addChild('img')->addAttribute('src', 'view/img/back.png');
            $div->img->addAttribute('id', 'main');

            $html->body->header->addChild('p');

            $html->xpath('//*[@class="main-body"]')[0]->
            addChild('div')->addAttribute('class', 'form-body');
            $htm = $html->xpath('//*[@class="form-body"]')[0];
            $htm->addChild('div')->addAttribute('class', 'cell');
            $htm->div->addChild('p', $page_info['login'] . ' was successfully activated.')->addAttribute('class', 'message');
            $dom->importNode(dom_import_simplexml($html), true);

            return $dom->saveHTML();
        }

        public function reset_page() {
            $dom = $this->dom_var();
            $html = $this->html_var($dom);

            $html->head->addChild('title', 'Reset');

            $div = $html->body->header->addChild('div');
            $div->addAttribute('id', 'return');
            $div->addChild('img')->addAttribute('src', 'view/img/back.png');
            $div->img->addAttribute('id', 'main');

            $html->body->header->addChild('p');

            $html->xpath('//*[@class="main-body"]')[0]->
            addChild('div')->addAttribute('class', 'form-body');
            $htm = $html->xpath('//*[@class="form-body"]')[0];
            for ($i = 0; $i < 3; $i++) {
                $htm->addChild('div')->addAttribute('class', 'cell');
            }
            $dom->importNode(dom_import_simplexml($html), true);

            return $dom->saveHTML();
        }
    }