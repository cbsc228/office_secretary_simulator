Welcome to my secretary simulator program!

-----DESCRIPTION-----

This program is intended to simulate a secretary accepting clients who come through the door and call in by phone.

Each client gets into line based on an individually randomized amount of time and had the time necessary to answer their
question randomized individually as well.
The random number generator is seeded using the current time of day.

New phone clients are given absolute priority and are placed in the front of the line as soon as they call in.

The line of clients is implemented using a queue class made from a linked list.

-----TO RUN THE PROGRAM-----

Within your terminal run the "make run" command in the directory containing the unzipped files which will compile
the necessary files into the executable and proceed to execute said file.

Running "make clean" will complile the program and prompt you as to whether or not you wish to remove the generated object files
as well as the executable file.

-----USING THE PROGRAM-----

When you initially execute the program it will give you a welcome message and proceed to ask you for necessary values.

If the values provided do not fall within the acceptable range the program returns a message stating so and will continue
to ask until an appropiate value is provided.

Once all the necessary values are obtained from the user the program will output the results of the simulator based on the randomization
of the user provided constraints.

Each output indicates the action that took place and the information about that particular client involved, the state of the queue
at that time, and the current time in the simulator.

Once the program has reached the end time indicted by the user the program terminates itself and can be run again using the same command
as before.