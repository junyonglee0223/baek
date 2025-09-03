import random

class NumberBaseballGame:
    def __init__(self):
        self.target_number = ""
        self.digits = 0
        self.attempts = 0
        self.max_attempts = 10
    
    def generate_target_number(self, digits):
        """Generate a random number with unique digits"""
        available_digits = list(range(10))
        # First digit cannot be 0
        first_digit = random.choice(range(1, 10))
        available_digits.remove(first_digit)
        
        target = [first_digit]
        
        for _ in range(digits - 1):
            digit = random.choice(available_digits)
            target.append(digit)
            available_digits.remove(digit)
        
        return ''.join(map(str, target))
    
    def validate_input(self, guess):
        """Validate user input"""
        if len(guess) != self.digits:
            return False, f"Please enter exactly {self.digits} digits."
        
        if not guess.isdigit():
            return False, "Please enter numbers only."
        
        if len(set(guess)) != len(guess):
            return False, "All digits must be unique."
        
        if guess[0] == '0':
            return False, "First digit cannot be 0."
        
        return True, ""
    
    def calculate_score(self, guess, target):
        """Calculate strikes and balls"""
        strikes = 0
        balls = 0
        
        for i in range(len(guess)):
            if guess[i] == target[i]:
                strikes += 1
            elif guess[i] in target:
                balls += 1
        
        return strikes, balls
    
    def play_game(self):
        """Main game loop"""
        print("=" * 50)
        print("🎯 Welcome to Number Baseball Game! 🎯")
        print("=" * 50)
        print("Rules:")
        print("- Guess a number with unique digits")
        print("- Strike: Correct digit in correct position")
        print("- Ball: Correct digit in wrong position")
        print("- Attempts: 3-digit(10), 4-digit(12), 5-digit(18)")
        print("=" * 50)
        
        # Choose difficulty
        while True:
            choice = input("Choose difficulty (3 for 3-digit, 4 for 4-digit, 5 for 5-digit): ").strip()
            if choice in ['3', '4', '5']:
                self.digits = int(choice)
                break
            else:
                print("Please enter 3, 4 or 5.")
        
        # Generate target number
        self.target_number = self.generate_target_number(self.digits)
        self.attempts = 0
        
        # Set max attempts based on difficulty
        if self.digits == 3:
            self.max_attempts = 10
        elif self.digits == 4:
            self.max_attempts = 15
        else:
            self.max_attempts = self.digits * 5  # For future expansion
        
        print(f"\n🎲 I've generated a {self.digits}-digit number with unique digits!")
        print("Let's start the game!\n")
        
        # Game loop
        while self.attempts < self.max_attempts:
            self.attempts += 1
            print(f"Attempt {self.attempts}/{self.max_attempts}")
            
            # Get user input
            guess = input(f"Enter your {self.digits}-digit guess: ").strip()
            
            # Validate input
            is_valid, error_message = self.validate_input(guess)
            if not is_valid:
                print(f"❌ {error_message}")
                self.attempts -= 1  # Don't count invalid attempts
                continue
            
            # Check if guess is correct
            if guess == self.target_number:
                print(f"🎉 Congratulations! You guessed it correctly!")
                print(f"The number was {self.target_number}")
                print(f"You solved it in {self.attempts} attempts!")
                return True
            
            # Calculate and display score
            strikes, balls = self.calculate_score(guess, self.target_number)
            print(f"Result: {strikes} Strike(s), {balls} Ball(s)")
            
            if strikes == 0 and balls == 0:
                print("💥 Out! No correct digits.")
            
            print("-" * 30)
        
        # Game over
        print(f"💀 Game Over! You've used all {self.max_attempts} attempts.")
        print(f"The correct number was: {self.target_number}")
        return False
    
    def play_again(self):
        """Ask if player wants to play again"""
        while True:
            choice = input("\nDo you want to play again? (y/n): ").strip().lower()
            if choice in ['y', 'yes']:
                return True
            elif choice in ['n', 'no']:
                return False
            else:
                print("Please enter 'y' for yes or 'n' for no.")

def main():
    """Main function to run the game"""
    game = NumberBaseballGame()
    
    print("🎮 Number Baseball Game Started! 🎮")
    
    while True:
        game.play_game()
        
        if not game.play_again():
            print("\n👋 Thanks for playing! Goodbye!")
            break

if __name__ == "__main__":
    main()