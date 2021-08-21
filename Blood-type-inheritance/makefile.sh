# Create automated compilation and code run in sh

# Pass in the number of generations
GENS="$1"

function MAKE_FILE()
{
    function COMPILE()
    {
        echo "Compiling blood-type.c"
        # Compile the program
        clang blood-type.c -o blood-type

    }
    function RUN()
    {
        echo "Running blood-type"
        # Run the script
        ./blood-type "$1"
    }

    COMPILE

    # Delay
    sleep 1.0s
    RUN "$1"
}

MAKE_FILE $GENS