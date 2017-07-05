insert into ft_table (login, creation_date, `group`) select last_name, birthdate, 'other' from user_card where last_name like '%a%' and length(last_name) < 9 order by last_name limit 10;
