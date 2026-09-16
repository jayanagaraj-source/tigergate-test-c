# Deliberately insecure IaC fixtures for scanner validation. DO NOT APPLY.
provider "aws" {
  region                      = "us-east-1"
  access_key                  = local.fixture_access_key
  secret_key                  = local.fixture_secret_key
  skip_credentials_validation = true
  skip_requesting_account_id  = true
}

# CKV_AWS_18/19/21: bucket without logging, encryption, or versioning
resource "aws_s3_bucket" "data" {
  bucket = "tigergate-test-c-data"
  acl    = "public-read" # CKV_AWS_20: public-read ACL
}

# CKV_AWS_23: security group open to the world on SSH
resource "aws_security_group" "open" {
  name        = "tigergate-open"
  description = "Fixture: ingress from 0.0.0.0/0"

  ingress {
    from_port   = 22
    to_port     = 22
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }
  ingress {
    from_port   = 0
    to_port     = 65535
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }
  egress {
    from_port   = 0
    to_port     = 0
    protocol    = "-1"
    cidr_blocks = ["0.0.0.0/0"]
  }
}

# CKV_AWS_17/16: unencrypted, publicly accessible RDS with inline password
resource "aws_db_instance" "fixture" {
  identifier          = "tigergate-fixture-db"
  engine              = "postgres"
  instance_class      = "db.t3.micro"
  allocated_storage   = 20
  username            = "admin"
  password            = "otDzZxIZV0TxcDMdva6cZ4ld" # CKV_SECRET
  publicly_accessible = true
  storage_encrypted   = false
  skip_final_snapshot = true
}

# CKV_AWS_58: EKS/EC2 metadata + unrestricted IAM policy
resource "aws_iam_policy" "admin_all" {
  name = "tigergate-admin-all"
  policy = jsonencode({
    Version = "2012-10-17"
    Statement = [{
      Effect   = "Allow"
      Action   = "*"
      Resource = "*"
    }]
  })
}

# CKV_AWS_8: unencrypted EBS volume
resource "aws_ebs_volume" "fixture" {
  availability_zone = "us-east-1a"
  size              = 8
  encrypted         = false
}
