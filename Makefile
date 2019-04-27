user.o: user.cpp user.h
	g++ -c $<
account.o: account.cpp account.h
	g++ -c $<
incomes.o: incomes.cpp incomes.h account.o
	g++ -c $<
expenses.o: expenses.cpp expenses.h account.o
	g++ -c $<
interestcal.o: interestcal.cpp interestcal.h
	g++ -c $<
BudgetSetting.o: BudgetSetting.cpp BudgetSetting.h
	g++ -c $<
TimeSetting.o: TimeSetting.cpp TimeSetting.h
	g++ -c $<
main.o: main.cpp user.o account.o incomes.o expenses.o interestcal.o BudgetSetting.o TimeSetting.o
	g++ -c $<
main: main.o user.o account.o incomes.o expenses.o interestcal.o BudgetSetting.o TimeSetting.o
	g++ $^ -o $@
	
clean:
	rm main *.o
	
clean_txt:
	rm *.txt
	
.PHONY: clean clean_txt
