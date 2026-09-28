# Step 1: Use an official C++ compiler as the base image
FROM gcc:latest

# Step 2: Set the working directory inside the container
WORKDIR /usr/src/app

# Step 3: Copy the C++ source code into the container
COPY main.cpp .

# Step 4: Compile the C++ program (creates an executable named 'microservice')
RUN g++ -o microservice main.cpp

# Step 5: Command to run the executable when the container starts
CMD ["./microservice"]
