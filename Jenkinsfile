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
            }
        }
        stage('Deploy') {
            steps {
                sh """
                echo 'Deploying.... ' 
                """
                archiveArtifacts artifacts: "build/*.deb", fingerprint: 'true'

            }
        }
    }
}
