# urm - Ultra RM

`urm` is a safer and more powerful alternative to `rm`, designed to prevent accidental file loss while offering secure deletion when needed. It moves files to a trash folder instead of immediate deletion, with options to recover or permanently erase files securely.

## Features

- **Safe Deletion**: Moves files and directories to `~/utrash/` instead of deleting them instantly.
- **Permanent Deletion (`-etr`)**: Securely wipes files before deletion.
- **Trash Management (`-trash`)**: Lists deleted files in `~/utrash/`.
- **Recovery (`-recover filename`)**: Restores files from trash.
- **Directory Support (`-d directory`)**: Moves directories to `~/utrash/` just like files.
- **Safety Measures**: Prevents accidental deletion of critical system files.

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
Developed with safety in mind. Use responsibly!
