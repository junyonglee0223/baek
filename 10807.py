num1 = input()
num2 = input()

ret = 0

for i in 3:
    tmp = num1 * (num2%10)
    num2/10
    print(tmp)
    ret += tmp * 10
    
print(ret)

