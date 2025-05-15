# List of adjourn Subcommands

## Entry Creation

- You can create a entry with the ENTRY_NAME as the title of entry in currently active diary. Diary defaults to the "default" name in lives in ~/documents folder.

`adjourn write $ENTRY_NAME`


- You can write to a different diary using the following command. If a diary does not exist, adjourn prompts user for confirmation then creates a new diary with the name.

`adjourn write $ENTRY_NAME -b $DIARY_NAME`

- To switch the active diary while making an entry, use the `-B` flag

`adjourn write $ENTRY_NAME -B $DIARY_NAME`
