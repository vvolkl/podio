pipeline {
    agent {label 'fcc-ubuntu'}

    stages {
            stage('Back-end') {
            agent {
                docker { image 'maven:3-alpine' }
            }
            steps {
                sh 'mvn --version'
            }
        }
        stage('Front-end') {
            agent {
                docker { 
                  image 'node:7-alpine' 
                }
            }
            steps {
                sh 'node --version'
            }
        }
        stage('Deploy') {
            agent {
              docker {
                  image 'gitlab-registry.cern.ch/sft/docker:cc7-lcg-cvmfs'
              }
            }
            steps {
                sh """
                echo 'Deploying.... ' 
                """

            }
        }
    }
}
