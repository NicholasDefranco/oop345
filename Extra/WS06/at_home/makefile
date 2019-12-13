objects = w6.o Sale.o Product.o

edit : $(objects)
	g++ -o w6 $(objects)

w6.o : Sale.h 
Product.o : Product.h 
Sale.o : Sale.h iProduct.h

.PHONY : clean
clean : 
	rm w6 $(objects)
