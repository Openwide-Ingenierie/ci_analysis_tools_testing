<a href="https://scan.coverity.com/projects/openwide-ingenierie-ci_analysis_tools_testing">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/20329/badge.svg"/>
</a>

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Openwide-Ingenierie_ci_analysis_tools_testing&metric=alert_status)](https://sonarcloud.io/dashboard?id=Openwide-Ingenierie_ci_analysis_tools_testing)

[![Total alerts](https://img.shields.io/lgtm/alerts/g/Openwide-Ingenierie/ci_analysis_tools_testing.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Openwide-Ingenierie/ci_analysis_tools_testing/alerts/)

# ci_analysis_tools_testing
A project to test code analysis tools

Generate bw output for sonarcloud analysis
> build-wrapper-linux-x86-64 --out-dir bw-output make clean all

Launch sonar analysis
> sonar-scanner   -Dsonar.projectKey=Openwide-Ingenierie_ci_analysis_tools_testing   -Dsonar.organization=openwide-ingenierie   -Dsonar.sources=.   -Dsonar.host.url=https://sonarcloud.io   -Dsonar.login=1651c30134c82e0106ef2c6b8c6db29f9f992592   -Dsonar.cfamily.build-wrapper-output=bw-output

Generate coverity build for coverity analysis
> make clean
> cov-build --dir cov-int make -j 4
> tar czvf citest.tgz cov-int
And send tar to coverity via Coverity import
