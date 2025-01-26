# ENC-HELPER

![ENC-HELPER Banner](https://via.placeholder.com/800x200.png?text=ENC-HELPER)  
*Encrypt and Decrypt Strings with Ease*

ENC-HELPER is a powerful command-line utility written in C that provides a suite of tools for string manipulation. With features for reversing strings, base64 encoding and decoding, and ROT13 encoding, this utility is designed for users who need quick and efficient text transformations.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Installation](#installation)
- [Examples](#examples)
- [License](#license)
- [Author](#author)

## Features

- **Reverse Strings**: Quickly reverse any input string.
- **Base64 Encoding**: Convert strings to base64 format for safe transmission or storage.
- **Base64 Decoding**: Decode base64 encoded strings back to their original form.
- **ROT13 Encoding**: Easily apply the ROT13 cipher for simple text obfuscation.
- **User-Friendly Interface**: Displays a welcoming banner and clear usage instructions.

## Usage

To use the ENC-HELPER utility, launch it from the command line with the desired option and the string you want to manipulate. The syntax is as follows:

```bash
./enc_helper [Option] [String]
```

### Available Options

- `rev`: Reverse the input string.
- `b64e`: Base64 encode the input string.
- `b64d`: Base64 decode the input string.
- `rot`: Rotate the input string using the ROT13 method.
- `help` or `h`: Display this help message.

## Installation

To compile and run the ENC-HELPER utility, follow these simple steps:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Anon4You/ENC-HELPER.git
   cd ENC-HELPER
   ```

2. **Compile the code**:
   ```bash
   gcc -o enc_helper enc_helper.c
   ```

3. **Run the utility**:
   ```bash
   ./enc_helper [Option] [String]
   ```

## Examples

Here are some practical examples of how to use ENC-HELPER:

```bash
# Reverse a string
./enc_helper rev "Hello, World!"
# Output: !dlroW ,olleH

# Base64 encode a string
./enc_helper b64e "Hello, World!"
# Output: SGVsbG8sIFdvcmxkIQ==

# Base64 decode a string
./enc_helper b64d "SGVsbG8sIFdvcmxkIQ=="
# Output: Hello, World!

# ROT13 encode a string
./enc_helper rot "Hello, World!"
# Output: Uryyb, Jbeyq!
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Author

**Alienkrishn** - [GitHub Profile](https://github.com/Anon4You)  
*Feel free to reach out for questions or collaboration!*

---

