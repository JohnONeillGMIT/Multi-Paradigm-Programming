n = int(input("Input a number: "))
kind = input("Do you want to do sum or product?; ")

sum = 0
product =1

if (kind == "sum"):
    for i in range(1,n+1):
        sum = sum+i
    print("the sum of 1 to %d is %d" %(n, sum) )
elif (kind == "product"):
    for i in range(1,n+1):
        product = product * i
    print("the product of 1 to %d is %d" %(n, product) )
else:
    print("ha")
