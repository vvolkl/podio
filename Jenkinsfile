pipeline {
    agent {label 'fcc-ubuntu'}

    stages {
        stage('Deploy') {
            agent {
              docker {
                  image 'gitlab-registry.cern.ch/sft/docker:cc7-lcg-cvmfs'
                  args '--privileged -it --entrypoint=/bin/bash'
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
