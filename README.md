# urm - Ultra RM

`urm` is a safe alternative to `rm`, made to prevent accidently deleting files with secure deletion. It moves files to a trash folder instead of deletion, with options to recover or permanently erase files

## Features

- **Safe Deletion**: Moves files and directories to `~/utrash/` instead of deleting them
- **Permanent Deletion (`-etr`)**: Securely wipes files before deleting them
- **Trash Management (`-trash`)**: Lists deleted files in `~/utrash/`.
- **Recovery (`-recover filename`)**: Restores files from trash.
- **Directory Support (`-d directory`)**: Moves directories to `~/utrash/` just like files.
- **Safety Measures**: Prevents deleting important system files.

## Installation
```sh
git clone https://github.com/Darky-Github/urm.git
cd urm
make
sudo make install
```

## Usage
### Move a file to trash
```sh
urm filename
```

### Move a directory to trash
```sh
urm -d directory
```

### List files in trash
```sh
urm -trash
```

### Recover a file from trash
```sh
urm -recover filename
```

### Permanently delete all files in trash
```sh
urm -etr
```

## Uninstallation
```sh
sudo make uninstall
```

## License
This project is licensed under the MIT License

---
Developed with safety in mind. Use responsibly
