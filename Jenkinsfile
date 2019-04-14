pipeline {
    agent any

    stages {
        stage('Build-ubuntu') {
            agent { label 'fcc-ubuntu' }
            steps {
                sh """
                source /etc/profile &&
                mkdir build install || true && 
                cd build && 
                cmake -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=../install   .. && 
                make -j `getconf _NPROCESSORS_ONLN` install  &&
                ctest -j `getconf _NPROCESSORS_ONLN` --test-load `getconf _NPROCESSORS_ONLN`  --output-on-failure  &&
                cpack --config ./CPackConfig.cmake -G DEB -D CMAKE_INSTALL_PREFIX=/usr/local
                """
                archiveArtifacts artifacts: "build/*.deb", fingerprint: 'true'

            }
        }
        stage('Deploy') {
            agent {
              docker {
                  image 'gitlab-registry.cern.ch/sft/docker:cc7-lcg-cvmfs'
                  args '--privileged '
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
