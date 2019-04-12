pipeline {
    agent any

    stages {
        stage('Build-ubuntu') {
            agent { label 'fcc-ubuntu' }
            steps {
                sh """
                mkdir build install || true && 
                cd build && 
                cmake -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=../install .. && 
                make -j `getconf _NPROCESSORS_ONLN` install &&
                cpack --config ./CPackConfig.cmake -G DEB
                """
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                sh """
                cd build && 
                ctest -j `getconf _NPROCESSORS_ONLN` --test-load `getconf _NPROCESSORS_ONLN`
                """
            }
        }
        stage('Deploy') {
            steps {
                sh """
                echo 'Deploying.... ' 
                """
                archiveArtifacts artifacts: "build/*.deb"

            }
        }
    }
}
