"""A simple command-line greeting program."""


def main():
    name = input("Enter your name: ")
    name = "".join(character for character in name if character.isalnum()).title()
    print(f"Hello, {name}!")


if __name__ == "__main__":
    main()


# Example test:
# Input:
#   aLi!ce123
# Expected output:
#   Enter your name: Hello, Alice123!
#
# Another example:
# Input:
#   jo-rdan_42
# Expected output:
#   Enter your name: Hello, Jordan42!
