user.o: user.cpp user.h
	g++ -c user.cpp
account.o: account.cpp account.h
	g++ -c account.cpp
incomes.o: incomes,cpp incomes.h account.o
	g++ -c incomes.cpp
expenses.o: expenses.cpp expenses.h account.o
	g++ -c expenses.cpp
interestcal.o: interestcal.cpp interestcal.h
	g++ -c interestcal.cpp
BudgetSetting.o: BudgetSetting.cpp BudgetSetting.h
	g++ -c BudgetSetting.cpp
TimeSetting.o: TimeSetting.cpp TimeSetting.h
	g++ -c TimeSetting.cpp
main.o: user.o account.o incomes.o expenses.o interestcal.o BudgetSetting.o TimeSetting.o main.cpp
	g++ -c main.cpp
