.name "Mighty Copier"
.comment "	ctrl+c ctrl+v (Win, Linux)
			cmd+c cmd+v (Mac)"

			st r1, 25
			ld %0, r2
			st r2, -12
			ldi %:live, %1, r1
live:		live %0
fork:		fork %:first
			zjmp %:live
third:		live %0
			ld %16777216, r2
			ld %5, r3
			ld %0, r4
			zjmp %:start
second:		live %0
			fork %:third
			live %0
			st r1, r2
			ld %6, r3
			ld %0, r4
			zjmp %:start
first:		live %0
			fork %:second
			live %0
			fork %:fourth
			live %0
			ld %1409417988, r2
			ld %11, r3
			ld %0, r4
			zjmp %:start
fourth:		live %0
			ld %184549376, r2
			ld %10, r3
			ld %0, r4
			zjmp %:start
start:		live %0
			sti r2, r3, r4
