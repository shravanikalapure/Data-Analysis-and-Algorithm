class Company:
    def __init__(self):
        self.x = 0
        self.y = 0
        print("      (Karatsuba Multiplication)          ")


    def count_digits(self, num):
        count = 0
        while num > 0:
            count += 1
            num //= 10
        return count

    def karatsuba(self, x, y, level=0):
        indent = "  " * level

        # Base case
        if x < 10 or y < 10:
            print(f"{indent}Base Case: {x} × {y} = {x * y}")
            return x * y

        n = max(self.count_digits(x), self.count_digits(y))
        half = n // 2
        power = 10 ** half

        # Splitting
        xH = x // power
        xL = x % power
        yH = y // power
        yL = y % power

        print(f"{indent}Splitting:")
        print(f"{indent}X = {x} → High: {xH}, Low: {xL}")
        print(f"{indent}Y = {y} → High: {yH}, Low: {yL}")
        print(f"{indent}Half digits = {half}\n")

        a = self.karatsuba(xH, yH, level + 1)
        b = self.karatsuba(xL, yL, level + 1)
        c = self.karatsuba(xH + xL, yH + yL, level + 1) - a - b

        result = a * (10 ** (2 * half)) + c * power + b

        print(f"{indent}Combine:")
        print(f"{indent}a = {a}, b = {b}, c = {c}")
        print(f"{indent}Result = {result}\n")

        return result

    def update(self):
        try:
            print("\n--- Update Transaction Data ---")
            self.x = int(input("Enter Transaction X: "))
            self.y = int(input("Enter Transaction Y: "))
            print("Transaction data updated successfully!")
        except ValueError:
            print("Invalid input! Enter integers only.")

    def result(self):
        if self.x == 0 or self.y == 0:
            print("Please enter transaction values first.")
            return

        print("\n--- Processing Transactions (Karatsuba) ---\n")
        final_result = self.karatsuba(self.x, self.y)

        print("\n==========================================")
        print("           TRANSACTION SUMMARY            ")
        print("==========================================")
        print(f"Transaction X : {self.x}")
        print(f"Transaction Y : {self.y}")
        print("------------------------------------------")
        print(f"Total Result  : {final_result}")
        print("==========================================")

        print("\n(Verification)")
        print(f"Python Multiplication Result : {self.x * self.y}")

c = Company()

while True:
    print("\n-------------- MENU --------------")
    print("1. Update Transaction Data")
    print("2. Show Total Transaction")
    print("3. Exit")
    print("----------------------------------")

    choice = input("Enter your choice (1-3): ")

    if choice == "1":
        c.update()
    elif choice == "2":
        c.result()
    elif choice == "3":
        print("\nExiting Company Database. Goodbye!")
        break
    else:
        print("Invalid choice. Please select 1, 2, or 3.")