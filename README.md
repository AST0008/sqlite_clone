# sqlite_clone

## Description

A simple SQLite-like database built in C with B-tree storage, supporting basic SQL operations (INSERT/SELECT) and persistent disk storage.

## Features

- B-tree based storage engine
- Basic SQL support (INSERT, SELECT)
- Persistent disk storage
- Interactive command-line interfacee

## Technologies Used

- C

## Installation

1.  Clone the repository:

    ```bash
    git clone <repository_url>
    cd sqlite_clone
    ```

2.  Compile the code:

    ```bash
    make
    ```

## Usage

1.  Run the compiled executable:

    ```bash
    ./sqlite_clone <database_file>
    ```

2.  Interact with the database using SQL commands. For example:

    ```sql
    INSERT INTO table_name (column1, column2) VALUES ('value1', 'value2');
    SELECT * FROM table_name;
    ```

##Example

```bash
$ ./main
db > insert 1 john john@email.com
Executed.
db > insert 2 jane jane@email.com
Executed.
db > select
(1, john, john@email.com)
(2, jane, jane@email.com)
Executed.
db > .exit
```

## Key Functions

**get_page():** Memory management for pages

**cursor_value():** Access data at cursor position

**leaf_node_insert():** Insert into leaf node

**leaf_node_split_and_insert():** Handle node splitting

**internal_node_insert():** Insert into internal node


## License

MIT License
