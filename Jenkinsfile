pipeline {
    agent any

    stages {
        stage('Build-lxplus') {
            agent { label 'fcc-cc7-cvmfs' }
            steps {
                sh """
                source init.sh && 
                mkdir build install || true && 
                cd build && 
                cmake -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=../install .. && 
                make -j `getconf _NPROCESSORS_ONLN` install;
                """
            }
        }
        stage('Build-ubuntu') {
            agent { label 'fcc-ubuntu' }
            steps {
                sh """
                mkdir build install || true && 
                cd build && 
                cmake -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=../install .. && 
                make -j `getconf _NPROCESSORS_ONLN` install;
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
                echo 'Deploying.... (skip)'
            }
        }
    }
}
