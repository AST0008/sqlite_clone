#ifndef DB_H
#define DB_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define TABLE_MAX_PAGES 100
#define PAGE_SIZE 4096
#define ROWS_PER_PAGE (PAGE_SIZE / sizeof(Row))
#define TABLE_MAX_ROWS (ROWS_PER_PAGE * TABLE_MAX_PAGES)

typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE + 1];
    char email[COLUMN_EMAIL_SIZE + 1];
} Row;

typedef struct {
    int file_descriptor;
    uint32_t file_length;
    void* pages[TABLE_MAX_PAGES];
} Pager;

typedef struct {
    uint32_t num_rows;
    Pager* pager;
} Table;

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct {
    StatementType type;
    Row row_to_insert;
} Statement;

InputBuffer* new_input_buffer();
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);
MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* statement, Table* table);
Table* db_open(const char* filename);
void db_close(Table* table);
void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);
void* row_slot(Table* table, uint32_t row_num);

#endif
