select `name` from distrib where id_distrib in (42, 62, 63, 64, 65, 66, 67, 68, 69, 71, 88, 89, 90) or length(replace(lower(`name`), 'y', '')) = length(lower(`name`)) - 2 limit 2, 5;
