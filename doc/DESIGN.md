# List of adjourn Subcommands

## Entry Creation
`write $ENTRY_NAME`
Creates a entry with the ENTRY_NAME as the title of entry in currently active diary. Diary defaults to the "default" name in lives in ~/documents folder.

You can write to a different diary using the following command. If a diary does not exist, adjourn prompts user for confirmation then creates a new diary with the name.
`write $ENTRY_NAME -b $DIARY_NAME`

To switch the active diary while making an entry, use the `-B` flag
`write $ENTRY_NAME -B $DIARY_NAME`
