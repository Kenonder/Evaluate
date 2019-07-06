evaluate:	evaluate.h evaluate.cpp
		g++ evaluate.cpp -o evaluate

run:		evaluate
		./evaluate expr1.txt < test1.txt
		./evaluate expr2.txt < test2.txt
		./evaluate expr3.txt < test3.txt

clean:
		rm -f evaluate
