pipeline {
    agent any

    stages {
        stage('Build-ubuntu') {
            agent { label 'fcc-ubuntu' }
            steps {
                sh """
                mkdir build install || true && 
                cd build && 
                cmake -DCMAKE_CXX_STANDARD=17  .. && 
                make -j `getconf _NPROCESSORS_ONLN` install DESTDIR=../install &&
                ctest -j `getconf _NPROCESSORS_ONLN` --test-load `getconf _NPROCESSORS_ONLN` &&
                cpack --config ./CPackConfig.cmake -G DEB DESTDIR=/usr/local
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
