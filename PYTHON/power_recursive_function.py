"""-
    Student: Nicole-Rene Newcomb
    Class: CIS024C Python Programming
    Description: program calculates an exponential value x^n
        using a recursive function call based on user input.
"""


# prints program header
def print_header():
    dividing_lines = '='*60
    
    print()
    print()
    print(dividing_lines)
    print("\t\tPOWER RECURSIVE FUNCTION")
    print(dividing_lines)
    print("\nThis program calculates x to the power of n.")


# function requests user input and validates input
def request_user_input():
    is_float = False
    is_int = False
    x_n = tuple()

    # validates that input for x is a floating point value
    while not is_float:
        x = input("\nPlease enter a floating point value for x: ")
        
        try:
            if x.find('.') > 0 and float(x):
                x = float(x)
                is_float = True
            else:
                print("\nInvalid input: please enter number with decimal places.")
        except:
            print("\nInvalid input: please enter a numerical floating point value.")

    # validates that input for n is an integer value
    while not is_int:
        n = input("\nPlease enter a positive integer value for n: ")
        
        try:
            if n.find('.') < 0 and int(n):
                n = int(n)
                if n > 0:
                    is_int = True
                else:
                    print("\nInvalid input: please enter a positive integer.")
            else:
                print("\nInvalid input: please enter a whole number without decimal places.")
        except:
            print("\nInvalid input: please enter a numerical integer value.")
    
    x_n = (x, n)

    return x_n


# recursive function that calculates value of base/exponent variables
def power(x, n):

    if n == 0:
        return 1
    else:
        return (x * power(x, n-1))


# outputs result in desired format based on result value
def output_result(x, n, result):
    if result < -99999.9:
        print ("\nThe result of {} to the power of {} is: {:,.0f}".format(x, n, result))
    
    elif result < -9999.99:
        print ("\nThe result of {} to the power of {} is: {:,.2f}".format(x, n, result))
    
    elif result < -999.999:
         print ("\nThe result of {} to the power of {} is: {:,.6g}".format(x, n, result))
    
    elif result < 1000:
        print ("\nThe result of {} to the power of {} is: {:.6g}".format(x, n, result))
    
    elif result < 10000:
        print ("\nThe result of {} to the power of {} is: {:,.2f}".format(x, n, result))

    else:
        print ("\nThe result of {} to the power of {} is: {:,.0f}".format(x, n, result))


# contains contents of main function
def main():
    runAgain = ""
    while runAgain != "no":
        runAgain = ""
        print_header()
        x, n = request_user_input()
        result = power(x, n)
        output_result(x, n, result)
        while runAgain not in ["yes", "no"]:
            runAgain = input("\nWould you like to use the program again? Enter yes/no: ").lower()

# checks that main function exists, then calls it
if __name__ == "__main__":
    main()