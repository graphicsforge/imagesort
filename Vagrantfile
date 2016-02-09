# -*- mode: ruby -*-
# vi: set ft=ruby :
project_name = "imagesort"
ip_address = "10.1.1.30"
project_directory = "/home/vagrant/imagesort"

Vagrant.configure("2") do |config|
  # All Vagrant configuration is done here. The most common configuration
  # options are documented and commented below. For a complete reference,
  # please see the online documentation at vagrantup.com.

  config.hostmanager.enabled = true
  config.hostmanager.manage_host = true

  config.vm.box = "ubuntu/trusty64"
  config.vm.synced_folder ".", project_directory,
                          mount_options: ['dmode=777','fmode=777'],
                          owner: "vagrant",
                          group: "vagrant"

  config.vm.synced_folder "../imagesort", "/home/vagrant/imagesort",
                          mount_options: ['dmode=777','fmode=777'],
                          owner: "vagrant",
                          group: "vagrant"

  config.vm.synced_folder "~/.aws", "/home/vagrant/.aws",
                          mount_options: ['dmode=777','fmode=777'],
                          owner: "vagrant",
                          group: "vagrant"

  config.vm.define project_name do |node|
    node.vm.hostname = project_name + ".local"
    node.vm.network :private_network, ip: ip_address
  end

  config.vm.provision :hostmanager

  config.vm.provider :virtualbox do |vb|
    vb.memory = 8192
    vb.cpus = 3
    vb.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
    vb.customize ["modifyvm", :id, "--natdnsproxy1", "on"]
  end
end
