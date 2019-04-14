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
                  args '--privileged -it --entrypoint="/usr/local/bin/entrypoint.sh"'
              }
            }
            steps {
                sh """
                source /cvmfs/sft.cern.ch/lcg/views/LCG_94/x86_64-centos7-gcc8-opt/setup.sh &&
                which root &&
                echo 'Deploying.... ' 
                """

            }
        }
    }
}
