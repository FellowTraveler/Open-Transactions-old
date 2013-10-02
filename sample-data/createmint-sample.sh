#!/bin/bash

#### Recreates mints for sample-data server assets.

server_id="r1fUoHwJOWCuK3WBAAySjmKYqsG6G2TYIxdqY6YNuuG"
server_user_id="voeqDVAJwDwROywFtg5mEyYpcu2dcPJRLFHYh7tyhqk"

##### game tokens
asset_id="7f8nlUn795x8931JParRnmKAyw8cegRyBMcFg9FccaF"
createmint ${server_id} ${server_user_id} ${asset_id}

##### US Dollars
asset_id="EYGad9FjZWgGKeVbgh2FbA0Hf8oP0XlnRyYCsvSIYKL"
createmint ${server_id} ${server_user_id} ${asset_id}

##### silver grams
asset_id="JY7kEFnm2c50CGNphdpgnlVo2hOZuLrBua5cFqWWR9Q"
createmint ${server_id} ${server_user_id} ${asset_id}

#### Bitcoins
asset_id="XU1Gu6sjcLxg260FmRgrSvRz9L0OohXRSEhlkeSd9j2"
createmint ${server_id} ${server_user_id} ${asset_id}
