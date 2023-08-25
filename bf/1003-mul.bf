/**
*number - user input
*multiplier- make user input twice as much
*/


numbers  int(input("Enter a numbers: "))
multiplier = int(input("Enter a multiplier:2 "))
stack = [number]
queue = [multiplier]
while stack:
    num = stack.pop()
    mult = queue.pop()
    product = num * mult
    print(f"The product of {num} and {mult} is {product}.")
    if stack:
        stack.append(num)
        queue.append(mult)
