pipeline {
    agent any
    
    stages {
        stage('Cleanup Workspace') {
            steps {
                echo 'Cleaning up the workspace...'
                cleanWs()
            }
        }
        
        stage('Checkout Code') {
            steps {
                echo 'Fetching latest code from GitHub...'
                checkout scm
            }
        }
        
        stage('Build C++ App') {
            steps {
                echo 'Compiling C++ code...'
                sh 'g++ -o microservice main.cpp'
            }
        }
        
        stage('Automated Test') {
            steps {
                echo 'Running tests on the C++ application...'
                sh './microservice'
            }
        }
        
        stage('Dockerize') {
            steps {
                echo 'Packaging application into a Docker container...'
                sh 'docker build -t devops-microservice:v1 .'
            }
        }
        
        stage('Deploy Container') {
            steps {
                echo 'Deploying Container to Production Environment...'
                sh 'docker run --rm devops-microservice:v1'
                echo 'CI/CD Pipeline Completed Successfully!'
            }
        }
    }
}
