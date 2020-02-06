# ci_analysis_tools_testing
A project to test code analysis tools

Generate bw output for snarcloud analysis
> build-wrapper-linux-x86-64 --out-dir bw-output make clean all

Launch sonar analysis
> sonar-scanner   -Dsonar.projectKey=Openwide-Ingenierie_ci_analysis_tools_testing   -Dsonar.organization=openwide-ingenierie   -Dsonar.sources=.   -Dsonar.host.url=https://sonarcloud.io   -Dsonar.login=1651c30134c82e0106ef2c6b8c6db29f9f992592   -Dsonar.cfamily.build-wrapper-output=bw-output
