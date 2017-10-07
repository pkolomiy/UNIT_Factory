<?php
    trait View {
        use Main, Setup, Extra;
        public function get_html($page_info) {
            if (is_array($page_info)) {
                switch ($page_info) {
                    case $page_info['page'] == 'main':
                        return $this->main_page($page_info);
                    case $page_info['page'] == 'setup':
                        return $this->setup_page($page_info);
                    case $page_info['page'] == 'activation';
                        return $this->activation_page($page_info);
                    case $page_info['page'] == 'reset';
                        return $this->reset_page();
                    default:
                        break;
                }
                return $this->lost_page();
            }
        }

        public function dom_var() {
            $dom = new DOMDocument;
            libxml_use_internal_errors(true);
            $dom->loadHTML(file_get_contents('view/pages/frame.html'));
            libxml_use_internal_errors(false);
            return $dom;
        }

        public function html_var($dom) {
            return simplexml_import_dom($dom);
        }
    }
