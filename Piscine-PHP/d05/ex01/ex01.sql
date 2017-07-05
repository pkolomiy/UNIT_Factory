create table ft_table (id int not null primary key auto_increment, login varchar(8) not null default 'toto', `group`  ENUM('staff', 'student', 'other') not null, creation_date date not null);
