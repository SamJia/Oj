:loop
gen >in
unknown<in >unknown_out
python right.py<in >right_out
FC unknown_out right_out
pause
goto loop