int main() {
    char line[10240];
    assert( fgets(line, 10240, stdin) != NULL );
    assert( line[strlen(line) - 1] == '\n'    );
    parse(line);
    return 0;
}
